import urllib3, subprocess, sys, datetime

# Flag for whether or not to keep HTML file after opening page
s = False

if len(sys.argv) > 1:
    if sys.argv[1] == "-s":
        s = True

url = input("Enter URL: ")
hdr = {'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.11 (KHTML, like Gecko) Chrome/23.0.1271.64 Safari/537.11',
       'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
       'Accept-Charset': 'ISO-8859-1,utf-8;q=0.7,*;q=0.3',
       'Accept-Encoding': 'none',
       'Accept-Language': 'en-US,en;q=0.8',
       'Connection': 'keep-alive'}

# Get html and write to local file
resp = urllib3.request("GET", url, headers=hdr)
dt_now = datetime.datetime.now().strftime("%m-%d-%Y[%H:%M:%S]")
newFileName = "webpage" + dt_now + ".html"
newFile = open(newFileName, "w")
newFile.write(resp.data.decode())
newFile.close()

# Open local html file in Firefox and delete file when done
subprocess.run("firefox ./{}".format(newFileName), shell=True, universal_newlines=True, check=True)

if s != True:
    subprocess.run("rm {}".format(newFileName), shell=True, universal_newlines=True, check=True)