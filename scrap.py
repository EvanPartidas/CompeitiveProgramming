f = open("links.txt","r")

links = f.readlines()
import selenium
from selenium import webdriver
import time
import re
import collections
import operator
selenium.webdriver.firefox.options.Options.headless = True
driver = webdriver.Firefox(".")
table = dict()
for link in links:
	driver.get(link)
	time.sleep(2)
	print(driver.current_url)
	rank = driver.find_element_by_css_selector("#contest-tabs > li:nth-child(4) > a:nth-child(1)")
	rank.click()
	elem = driver.find_element_by_id("contest-rank-table")
	rows = elem.find_elements_by_class_name("this")
	for row in rows:
			name =  row.find_element_by_xpath("./td[2]/div/a").text
			name =  re.findall("\(.*\)", name)[0][1:-1]
			score = int(row.find_element_by_xpath("./td[3]/a").text)
			print(name)
			print(score)
			if not name in table:
				table[name] = score
			else:
				table[name]+=score
sorted_x = sorted(table.items(), key=operator.itemgetter(1), reverse=True)
table = collections.OrderedDict(sorted_x)
print("<table border=\"1\">\n  <tr>\n    <th>Rank</th> \n    <th>User</th>\n    <th>Score</th>\n  </tr>")
rank = 1
for key in table.keys():
	print("<tr>")
	print("<td>"+str(rank)+"</td>")
        print("<td>"+key+"</td>")
        print("<td>"+str(table[key])+"</td>")
	print("</tr>")
	rank+=1
print("</tr>\n</table>")
