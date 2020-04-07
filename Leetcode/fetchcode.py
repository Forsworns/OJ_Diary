import requests
import json
import os
from time import sleep

# 对leetcode，不添加csrf token和referer会无法访问，同时访问频率也被限制了

if __name__ == "__main__":
    user = os.environ.get("LEETCODE_NAME")
    password = os.environ.get("LEETCODE_PASSWORD")
    login_url = 'https://leetcode-cn.com/accounts/login/'  # session模拟登陆后利用session中的cookies去保持登陆状态获取个人题解
    logout_url = 'https://leetcode.com/accounts/logout/'

    limit = 10 # 最大是20
    offset = 0

    session = requests.session()
    session.get(login_url)
    csrf_token = session.cookies.get('csrftoken') 
    session.post(login_url, data={'csrfmiddlewaretoken': csrf_token,
                                  'login': user,
                                  'password': password,
                                  'next': '/submissions'}, headers={"referer": login_url})
    has_next = True
    while has_next:
        response = session.get(
            "https://leetcode-cn.com/api/submissions/?offset={}&limit={}&lastkey=".format(offset, limit))
        if response.status_code == 200:
            print("submission offset:"+str(offset))
            response = response.json()
            has_next = response["has_next"]
            submissions = response["submissions_dump"]
            offset += len(submissions)
            for item in submissions:
                if item['status_display'] == 'Accepted':
                    title, sid, lang = item['title'], item['id'], item['lang']
                    if not os.path.exists(lang):
                        os.mkdir(lang)
                    file_name = "{}/{}_{}.{}".format(lang,title,sid,lang)
                    if not os.path.exists(file_name):
                        with open(file_name,"w",encoding='utf-8') as f:
                            f.write(item['code'])
            sleep(1.5) # 防止过高频率访问
        else:
            print("ERROR CODE {}: {}".format(
                response.status_code, response.json()["detail"]))
            break
    session.get(logout_url)
    session.close()
