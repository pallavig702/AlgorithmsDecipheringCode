#!usr/bin
if [ "$1" != "" ] && [ "$2" != "" ];
then
    if [ $2 -lt 11 ]; then
        #echo "Time: $(date -Iseconds)"
	    #Remove all the non alphabetic characters
        cat $1 | tr -d "\r\n" | sed "s/\ //g" |  sed 's/[^a-zA-Z]//g' | perl -ne 'print lc' > test3.txt
	    #To print the tuples
	    python RPM.py test3.txt $2 > File.txt
	    #To sort the tuples into their distribution
	    cat File.txt | sort | uniq -c | sort -rn | awk '{print $2" "$1}'
        rm test3.txt File.txt
       # echo "Time: $(date -Iseconds)"

    else
        echo "Error: Please provide K value <= 10"
    fi
else 	
	echo " bash Run.sh <filename> <k>"
	echo "Error: Provide the text filename and k-tuples value"
fi
