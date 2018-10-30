#!/bin/sh
for filename in *.txt; do
	echo "File name: $filename"
	tr '[A-Z]' '[a-z]' < $filename > temp.txt
	sed -i -e 's/SEECS/school of electrical engineering and computer science/g' $filename
	sed -i -e 's/NUST/national university of sciences and technology/g' $filename
	cat temp.txt > $filename
	rm temp.txt
	input=`expr $filename`
	while IFS= read -r var
	do
		if [[ $var =~ ^[0-9] ]]; then
			outp=`expr $var | sed 's/[^0-9]*//g'`
			echo $outp
			case $outp in 
				453) sed -i -e 's/453/four hundred and fifty three/g' $filename ;;
				656) sed -i -e 's/656/six hundred and fifty six/g' $filename ;;
				763) sed -i -e 's/763/seven hundred and sixty three/g' $filename ;;
				9123) sed -i -e 's/9123/nine thousand and twenty three/g' $filename ;;
				2134) sed -i -e 's/2134/two thousand and thirty four/g' $filename ;;
			esac
		fi
	done < "$input"
done
