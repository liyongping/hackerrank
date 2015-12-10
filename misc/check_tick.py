# -*- coding: utf-8 -*-

import httplib2
import socks
import json
import time
import smtplib  

from email.message import Message
import email.utils

import sys
'''
Use following 2 lines to resolve: 
    UnicodeEncodeError: 'ascii' codec can't encode characters in position 7-8: ordinal not in range(128)
''' 
reload(sys)
sys.setdefaultencoding( "utf-8" )


interval_time = 60 #second

smtpserver = 'smtp.163.com'  
username = '****@163.com'  
password = '*****'
receiver = '*****'

def sendmail(subject,body):
    message = Message()
    message['Subject'] = subject
    message['From'] = username
    message['To'] = receiver
    message.set_payload(body) 
      
    smtp = smtplib.SMTP()  
    smtp.connect(smtpserver)  
    smtp.login(username, password)  
    smtp.sendmail(sender, receiver, message.as_string())  
    time.sleep(5)
    smtp.quit() 

def task():
    #httplib2.debuglevel=4
    '''h = httplib2.Http(".cache", disable_ssl_certificate_validation=True,
    				proxy_info = httplib2.ProxyInfo(socks.PROXY_TYPE_HTTP, '----------', 80)
    				)'''

    h = httplib2.Http(".cache", disable_ssl_certificate_validation=True)

    headers = {'Host': 'kyfw.12306.cn',
    'Connection': 'keep-alive',
    'Cache-Control': 'no-cache',
    'Accept': '*/*',
    'X-Requested-With': 'XMLHttpRequest',
    'If-Modified-Since': '0',
    'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/47.0.2526.80 Safari/537.36',
    'Referer': 'https://kyfw.12306.cn/otn/leftTicket/init',
    'Accept-Encoding': 'gzip, deflate, sdch',
    'Accept-Language': 'en-US,en;q=0.8'
    }
    response, content = h.request("http://kyfw.12306.cn/otn/leftTicket/queryT?leftTicketDTO.train_date=2016-02-05&leftTicketDTO.from_station=SZH&leftTicketDTO.to_station=LYS&purpose_codes=ADULT",
    	 "GET", headers=headers)

    if response['status'] == '200':
        c = json.loads(content, encoding='utf-8')
        if c['httpstatus'] == 200:
            data = c['data']
            for di in data:
                station_train_code = di['queryLeftNewDTO']['station_train_code']
                from_station_name = di['queryLeftNewDTO']['from_station_name']
                to_station_name = di['queryLeftNewDTO']['to_station_name']
                start_time = di['queryLeftNewDTO']['start_time']
                arrive_time = di['queryLeftNewDTO']['arrive_time']

                buttonTextInfo = di['buttonTextInfo'].replace('<br/>', ': ')
                info = station_train_code + ': ' + from_station_name + \
                    '-->' + to_station_name + '     ' + \
                    start_time + '-->' + arrive_time + \
                    '           ' + buttonTextInfo
                print info
                if di['buttonTextInfo'] !='暂售至: 01月09日' \
                    and di['buttonTextInfo'] != '23:00-07:00系统维护时间':
                    sendmail(info,info)
        
    else:
    	print 'missing info'

if __name__ == '__main__':
    #sendmail('ceshi ouxiang ','test')
    i = 10
    while True:  
        print time.strftime('%Y-%m-%d %X',time.localtime()) +"   checked."
        task()
        time.sleep(interval_time)
        i = i-1
        if i == 0:
            break
            #pass