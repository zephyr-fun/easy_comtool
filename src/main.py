import wx
import sys, os
import win
import formatter
import serial
import serial.tools.list_ports
import threading
import logging
import matplotlib
import matplotlib.pyplot as plt
import socket
import time

s_serialPort = serial.Serial()
s_recvInterval = 0.05
s_plotInterval = 0.05

s_recvStatusFieldIndex = 0
s_sendStatusFieldIndex = 1
s_infoStatusFieldIndex = 2

s_recvStatusStr = 'Recv: '
s_recvTotalBytes = 0
s_sendStatusStr = 'Send: '
s_sendTotalBytes = 0

s_formatter = formatter.formatter()
s_lastRecvFormat = None
s_lastSendFormat = None

m_plot = ''

ax = []
ay = []
def tcplink(sock, addr):
    print('Accept new connection from %s:%s...' % addr)
    sock.send(b'Welcome!')
    while True:
        data = sock.recv(1024)
        time.sleep(0.01)
        if not data or data.decode('utf-8') == 'exit':
            break
        sock.send(('Working Well, %s!' % data.decode('utf-8')).encode('utf-8'))
    sock.close()
    print('Connection from %s:%s closed.' % addr)
class mainWin(win.com_win):

    def __init__(self, parent):
        win.com_win.__init__(self, parent)
        icon = wx.Icon()
        icon.CopyFromBitmap(wx.Bitmap( u"../img/Jays-PyCOM.ico", wx.BITMAP_TYPE_ANY))
        self.SetIcon(icon)
        self.m_bitmap_led.SetBitmap(wx.Bitmap( u"../img/led_black.png", wx.BITMAP_TYPE_ANY ))
        self.refreshComPort(None)
        self.m_choice_comPort.SetSelection( 0 )

    def refreshComPort( self, event ):
        comports = list(serial.tools.list_ports.comports())
        ports = [None] * len(comports)
        for i in range(len(comports)):
            comport = list(comports[i])
            # example comport = [u'COM3', u'Intel(R) Active Management Technology - SOL (COM3)', u'PCI\\VEN_8086&DEV_9D3D&SUBSYS_06DC1028&REV_21\\3&11583659&0&B3']
            ports[i] = comport[0] + ' - ' + comport[1]
        self.m_choice_comPort.Clear()
        self.m_choice_comPort.SetItems(ports)

    def setPort ( self ):
        index = self.m_choice_comPort.GetSelection()
        comPort = self.m_choice_comPort.GetString(index)
        comPort = comPort.split(' - ')
        s_serialPort.port = comPort[0]

    def setBaudrate ( self ):
        index = self.m_choice_baudrate.GetSelection()
        s_serialPort.baudrate = int(self.m_choice_baudrate.GetString(index))

    def setDatabits ( self ):
        index = self.m_choice_dataBits.GetSelection()
        m_dataBits = int(self.m_choice_dataBits.GetString(index))
        if m_dataBits == 5:
            s_serialPort.bytesizes = serial.FIVEBITS
        elif m_dataBits == 6:
            s_serialPort.bytesizes = serial.SIXBITS
        elif m_dataBits == 7:
            s_serialPort.bytesizes = serial.SEVENBITS
        elif m_dataBits == 8:
            s_serialPort.bytesizes = serial.EIGHTBITS
        else:
            pass

    def setStopbits ( self ):
        index = self.m_choice_stopBits.GetSelection()
        m_stopBits = self.m_choice_stopBits.GetString(index)
        if m_stopBits == '1':
            s_serialPort.stopbits = serial.STOPBITS_ONE
        elif m_stopBits == '1.5':
            s_serialPort.stopbits = serial.STOPBITS_ONE_POINT_FIVE
        elif m_stopBits == '2':
            s_serialPort.stopbits = serial.STOPBITS_TWO
        else:
            pass

    def setParitybits ( self ):
        index = self.m_choice_parityBits.GetSelection()
        m_parityBits = self.m_choice_parityBits.GetString(index)
        if m_parityBits == 'None':
            s_serialPort.parity = serial.PARITY_NONE
        elif m_parityBits == 'Odd':
            s_serialPort.parity = serial.PARITY_ODD
        elif m_parityBits == 'Even':
            s_serialPort.parity = serial.PARITY_EVEN
        elif m_parityBits == 'Mark':
            s_serialPort.parity = serial.PARITY_MARK
        elif m_parityBits == 'Space':
            s_serialPort.parity = serial.PARITY_SPACE
        else:
            pass

    def openClosePort( self, event ):
        if s_serialPort.isOpen():
            s_serialPort.close()
            self.m_button_openClose.SetLabel('Open')
            self.m_bitmap_led.SetBitmap(wx.Bitmap( u"../img/led_black.png", wx.BITMAP_TYPE_ANY ))
            self.statusBar.SetStatusText(s_serialPort.name + ' is closed', s_infoStatusFieldIndex)
        else:
            self.statusBar.SetFieldsCount(3)
            self.statusBar.SetStatusWidths([150, 150, 400])
            self.setPort()
            self.setBaudrate()
            self.setDatabits()
            self.setStopbits()
            self.setParitybits()
            try:
                s_serialPort.open()
            except Exception as err:
                self.statusBar.SetStatusText(s_serialPort.name + ' doesn\'t exist !!!', s_infoStatusFieldIndex)
                return
            self.m_button_openClose.SetLabel('Close')
            self.m_bitmap_led.SetBitmap(wx.Bitmap( u"../img/led_green.png", wx.BITMAP_TYPE_ANY ))
            self.statusBar.SetStatusText(s_recvStatusStr + str(s_recvTotalBytes), s_recvStatusFieldIndex)
            self.statusBar.SetStatusText(s_sendStatusStr + str(s_sendTotalBytes), s_sendStatusFieldIndex)
            self.statusBar.SetStatusText(s_serialPort.name + ' is open, ' +
                                               str(s_serialPort.baudrate) + ', ' +
                                               str(s_serialPort.bytesizes) + ', ' +
                                               s_serialPort.parity + ', ' +
                                               str(s_serialPort.stopbits), s_infoStatusFieldIndex)
            s_serialPort.reset_input_buffer()
            s_serialPort.reset_output_buffer()
            threading.Timer(s_recvInterval, self.recvData).start()

    def clearSendDisplay( self, event ):
        self.m_textCtrl_send.Clear()

    def setSendFormat( self, event ):
        lines = self.m_textCtrl_send.GetNumberOfLines()
        if lines != 0:
            m_sendFormat = self.m_choice_sendFormat.GetString(self.m_choice_sendFormat.GetSelection())
            global s_lastSendFormat
            if s_lastSendFormat == m_sendFormat:
                return
            else:
                s_lastSendFormat = m_sendFormat
            # Get existing data from textCtrl_send
            data = ''
            for i in range(0, lines):
                data += str(self.m_textCtrl_send.GetLineText(i))
            # Convert data format according to choice_sendFormat
            if m_sendFormat == 'Char':
                status, data = s_formatter.hexToChar(data)
                if not status:

                    self.m_textCtrl_send.Clear()
                    self.m_textCtrl_send.write('Invalid format! Correct example: 12 34 56 ab cd ef')
                    return
                self.m_textCtrl_send.Clear()
                self.m_textCtrl_send.write(data.encode())
            elif m_sendFormat == 'Hex':#!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                data = s_formatter.charToHex(data)
                self.m_textCtrl_send.Clear()
                self.m_textCtrl_send.write(data)
            # Re-show converted data in textCtrl_send
            #self.m_textCtrl_send.Clear()
            #self.m_textCtrl_send.write(data.decode())

    def sendData( self, event ):
        #logging.critical('test critical')#for test the function of console print
        if s_serialPort.isOpen():
            lines = self.m_textCtrl_send.GetNumberOfLines()
            #s_serialPort.write(lines)
            if lines != 0:
                # Get existing data from textCtrl_send
                data = ''
                for i in range(0, lines):
                    data += str(self.m_textCtrl_send.GetLineText(i))
                # Make sure data is always in 'Char' format
                m_sendFormat = self.m_choice_sendFormat.GetString(self.m_choice_sendFormat.GetSelection())
                if m_sendFormat == 'Hex':
                    status, data = s_formatter.hexToChar(data)
                    if not status:
                        self.m_textCtrl_send.Clear()
                        self.m_textCtrl_send.write('Invalid format! Correct example: 12 34 56 ab cd ef')
                        return
                    #else :

                # Send out data via Port
                s_serialPort.write(data.encode())#data.encode()
                #TypeError: unicode strings are not supported, please encode to bytes,need to add .encode()function
                #s_serialPort.write("asd".encode())  
                # Update send info in status bar
                global s_sendTotalBytes
                s_sendTotalBytes += len(data)
                self.statusBar.SetStatusText(s_sendStatusStr + str(s_sendTotalBytes), s_sendStatusFieldIndex)
        else:
            self.statusBar.SetStatusText(s_serialPort.name + ' is not open !!!', s_infoStatusFieldIndex)

    def clearRecvDisplay( self, event ):
        self.m_textCtrl_recv.Clear()

    def setRecvFormat( self, event ):
        lines = self.m_textCtrl_recv.GetNumberOfLines()
        if lines != 0:
            m_recvFormat = self.m_choice_recvFormat.GetString(self.m_choice_recvFormat.GetSelection())
            global s_lastRecvFormat
            if s_lastRecvFormat == m_recvFormat:
                return
            else:
                s_lastRecvFormat = m_recvFormat
            # Get existing data from textCtrl_recv
            data = ''
            for i in range(0, lines):
                data += str(self.m_textCtrl_recv.GetLineText(i))
            # Convert data format according to choice_recvFormat
            if m_recvFormat == 'Char':
                status, data = s_formatter.hexToChar(data)
                self.m_textCtrl_recv.Clear()
                self.m_textCtrl_recv.write(data)
            elif m_recvFormat == 'Hex':
                data = s_formatter.charToHex(data)
                self.m_textCtrl_recv.Clear()
                self.m_textCtrl_recv.write(data)
            # Re-show converted data in textCtrl_recv
            #self.m_textCtrl_recv.Clear()
            #self.m_textCtrl_recv.write(data)

    def recvData( self ):
        if s_serialPort.isOpen():
            num = s_serialPort.inWaiting()
            if num != 0:
                # Receive new data from Port
                data = s_serialPort.read(num).decode()
                #self.m_textCtrl_recv.write(data)
                # Note: Assume that data is always in 'Char' format
                # Convert data format if dispaly format is 'Hex'
                m_recvFormat = self.m_choice_recvFormat.GetString(self.m_choice_recvFormat.GetSelection())
                if m_recvFormat == 'Hex':
                    datahex = s_formatter.charToHex(data)
                    self.m_textCtrl_recv.write(datahex)
                else :
                    self.m_textCtrl_recv.write(data)
                    #self.m_textCtrl_recv.write(str(type(data)))#判断data的类型，为str

                # Show new data in textCtrl_recv
                #self.m_textCtrl_recv.write(data)

                # Update recv info in status bar
                global s_recvTotalBytes
                if m_recvFormat == 'Hex':
                    s_recvTotalBytes += int(len(datahex)/3)
                    #halfvalue = chr(int(ord(data)/2))
                    trans_mid1 = bytearray.fromhex(datahex)
                    trans_mid2 = list(trans_mid1)
                    halfvalue = chr(int(trans_mid2[0]/2))
                else :
                    s_recvTotalBytes += len(data)
                    halfvalue = chr(int(ord(data)/2))
                self.statusBar.SetStatusText(s_recvStatusStr + str(s_recvTotalBytes), s_recvStatusFieldIndex)
                global s_sendTotalBytes
                if data >= '*' :#default limitation
                    #atest = 0x2a
                    s_serialPort.write('w'.encode())
                    s_sendTotalBytes += 1
                #trans_mid1 = bytearray.fromhex(data)
                #trans_mid2 = list(trans_mid1)
                global ax
                global ay
                ax.append(s_recvTotalBytes)
                ay.append(ord(data))
                s_serialPort.write(halfvalue.encode())
                s_sendTotalBytes += 2
                self.statusBar.SetStatusText(s_sendStatusStr + str(s_sendTotalBytes), s_sendStatusFieldIndex)
                if m_plot == 'Plot_On':
                    # plt.ion()
                    
                    plt.scatter(ax,ay)
                    # plt.cla()
                    # plt.ioff()

                # else:
                #     plt.ioff()

            threading.Timer(s_recvInterval, self.recvData).start()
            # global m_plot
            # if m_plot == 'Plot_On':
            #     plt.ion()
            #     plt.scatter(ax,ay)
    def changeAnaline( self, event ):
        #logging.critical('test critical')
        # self.m_textCtrl_recv.write('???')
        if s_serialPort.isOpen():
            m_line = self.m_choice_line.GetString(self.m_choice_line.GetSelection())
            global s_sendTotalBytes
          #self.m_textCtrl_recv.write('1'.encode())
          # s_serialPort.write(m_line.encode())
            if m_line == 'Line#1':
                s_serialPort.write('1'.encode())
                s_sendTotalBytes += 1
            else :
                s_serialPort.write('2'.encode())
                s_sendTotalBytes += 1
            self.statusBar.SetStatusText(s_sendStatusStr + str(s_sendTotalBytes), s_sendStatusFieldIndex)
        else:
            self.statusBar.SetStatusText(s_serialPort.name + ' is not open !!!', s_infoStatusFieldIndex)
    def setPlotState( self, event ):
        if s_serialPort.isOpen():
            global m_plot
            m_plot = self.m_choice_plot.GetString(self.m_choice_plot.GetSelection())
            # global ax
            # global ay
            if m_plot == 'Plot_On':
                plt.ion()
                plt.scatter(ax,ay)
            # else:
            #     plt.ioff()

            # threading.Timer(s_recvInterval, self.setPlotState).start()
            # if m_plot == 'Plot_On':
            #     # plt.ion()
            #     # plt.scatter(ax,ay)
            # else:
            #     plt.ioff()
    def showHomepageMessage( self, event ):
        messageText = (('Code: \n    https://github.com/zepher-fun/zephyr-comtool.git \n'))
        wx.MessageBox(messageText, "Homepage", wx.OK | wx.ICON_INFORMATION)

    def showAboutMessage( self, event ):
        messageText = (('Author: Zephyr \n') +
                       ('Email: fanxuanzhe0106@gmail.com \n'))
        wx.MessageBox(messageText, "About", wx.OK | wx.ICON_INFORMATION)



    def OpenServer( self, event ):
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        # 监听端口:
        s.bind(('127.0.0.1', 8888))
        s.listen(5)
        print('Waiting for connection...')
        while True:
            # 接受一个新连接:
            sock, addr = s.accept()
            # 创建新线程来处理TCP连接:
            # t = threading.Thread(target=tcplink, args=(sock, addr))
            # t.start()
            tcplink(sock, addr)
            time.sleep(0.5)
            # s.close()



if __name__ == '__main__':
    app = wx.App()

    main_win = mainWin(None)
    main_win.SetTitle(u"Zephyr-PyCOM v1.0.0")
    main_win.Show()

    app.MainLoop()
