注册：
请求端：
    request:{"type":1, "username":"xxx", "passwd":"xxxxx"}
响应端：
    response:{"type":1, "result":"success", "reason":"XXX"}

登录：
请求端：
    request:{"type":1, "username":"xxx", "passwd":"xxxxx"}
响应端：
    response:{"type":1, "result":"success", "reason":"XXX"}

## 搜索歌曲:
### 请求端：
    request:{"type":SEARCH_MUSIC, "musicName":"一直很安静"}
### 回复端:
    response:{"type":SEARCH_MUSIC, "musicName":"一直很安静", "musicContent":"xxxx"}

## 下载音乐：
### 请求端：
    request:{"type":Download, "musicName":"我怀念的"}
### 响应端：
    response:{"type":Download, "musicName":"我怀念的", "musicContent":"xxxx"}