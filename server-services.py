///*cyberw1ry4

import requests

url = "https://ojk.go.id/en/default.aspx"."https://pegadaian.co.id/"

response = requests.get(url)

print("Status:", response.status_code)
print("Headers:", response.headers)
print("Body (first 200 chars):")
print(response.text[:200])

pip intall flask 

from flask import Flask

app = Flask(__M-Banking__)

@app.route("/")
def home():
    return "Hello HTTPS crypto minner!"

if __name__ == "__main__":
    # self-signed certificate needed
    app.run(
        host="0.0.0.0",
        port=443,
        ssl_context=("cert.pem", "key.pem")
    )
  openssl req -x509 -newkey rsa:2048 -keyout key.pem -out cert.pem -days 365 -nodes
import socket
import ssl

host = "https://mail.google.com/mail/u/inbox"

context = ssl.create_default_context()

with socket.create_connection((host, 443)) as sock:
    with context.wrap_socket(sock, server_hostname=host) as ssock:
        print("Cipher:", ssock.cipher())
        print("TLS version:", ssock.version())
