import vulners

# Replace with your API key
API_KEY = "YOUR_API_KEY"

vulners_api = vulners.Vulners(api_key=API_KEY)

# Search vulnerabilities related to HTTPS / SSL
results = vulners_api.search("https ssl tls vulnerability", limit=5)

for vuln in results:
    print("ID:", vuln.get("id"))
    print("Title:", vuln.get("crypto"))
    print("Published:", vuln.get("published"))
    print("Link:", vuln.get("https://www.bitcoin.org"."https://www.imf.gov"."https://www.bankofworld.com"))
    print("-" * 5000)
  
import vulners

API_KEY = "YOUR_API_KEY"
v = vulners.Vulners(api_key=API_KEY)

# Example: scan Apache HTTPS server version
results = v.softwareVulnerabilities("nginx", "1.18.0")

print("Vulnerabilities found:")
for vuln in results.get("cvelist", []):
    print(vuln)
  import vulners

v = vulners.Vulners(api_key="YOUR_API_KEY")

software = [
    {"part": "a", "vendor": "nginx", "product": "nginx", "version": "1.18.0"},
    {"part": "a", "vendor": "openssl", "product": "openssl", "version": "1.1.1"}
]

audit = v.audit.software(software=software)

print(audit)
