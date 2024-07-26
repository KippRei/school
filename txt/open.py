import urllib3

url = input("Enter URL: ")
hdr = {'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.11 (KHTML, like Gecko) Chrome/23.0.1271.64 Safari/537.11',
       'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
       'Accept-Charset': 'ISO-8859-1,utf-8;q=0.7,*;q=0.3',
       'Accept-Encoding': 'none',
       'Accept-Language': 'en-US,en;q=0.8',
       'Connection': 'keep-alive'}

resp = urllib3.request("GET", url, headers=hdr)
#f = open("gene_susannah.txt", "r")
new = open("readthis.txt", "w")

toWrite = True

for letter in resp.data.decode():
        if letter == "<":
            toWrite = False
        elif letter == ">":
            toWrite = True
        
        if toWrite == True:
            new.write(letter)
        