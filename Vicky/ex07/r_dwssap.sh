cat /etc/passwd | awk -F ':' '{print $1}' | rev | sort -r | tr '\n' ',' | sed 's/,/, /g' | sed 's/$/./'
