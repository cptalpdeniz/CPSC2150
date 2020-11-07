#!/bin/sh
echo 'island as shown in the assignment sheet'
colour.exe -input "inFolder/island.txt" -output "outFolder/island35.txt" -i 3 -j 5 -stack
echo 'island as shown in the assignment sheet'
colour.exe -input "inFolder/island.txt" -output "outFolder/island114.txt" -i 1 -j 14 -recursive
echo 'upper island as shown in the assignment sheet'
colour.exe -input "inFolder/island.txt" -output "outFolder/island215.txt" -i 2 -j 15 -recursive 
echo 'windy path'
colour.exe -input "inFolder/path.txt" -output "outFolder/path.txt" -i 3 -j 14 -queue 
echo 'upper right corner'
colour.exe -input "inFolder/path.txt" -output "outFolder/path018.txt" -i 0 -j 18 -stack
echo 'left side'
colour.exe -input "inFolder/path.txt" -output "outFolder/path91.txt" -i 9 -j 1 -recursive 
echo 'roads and upper right'
colour.exe -input "inFolder/roads.txt" -output "outFolder/roads.txt" -i 5 -j 10 -stack
echo 'expect no colour'
colour.exe -input "inFolder/dot_in_park.txt" -output "outFolder/dot_in_park68.txt" -i 6 -j 8 -recursive 
echo 'full park'
colour.exe -input "inFolder/dot_in_park.txt" -output "outFolder/dot_in_park58.txt" -i 5 -j 8 -recursive 
echo 'from empty to full'
colour.exe -input "inFolder/empty.txt" -output "outFolder/empty48.txt" -i 4 -j 8 -stack
echo 'from empty to full upper left hand corner'
colour.exe -input "inFolder/empty.txt" -output "outFolder/empty00.txt" -i 0 -j 0 -queue
echo 'colour lower'
colour.exe -input "inFolder/peninsula.txt" -output "outFolder/peninsula918.txt" -i 9 -j 18 -queue
echo 'colour upper'
colour.exe -input "inFolder/peninsula.txt" -output "outFolder/peninsula55.txt" -i 5 -j 5 -queue
echo 'colour city'
colour.exe -input "inFolder/city.txt" -output "outFolder/city59.txt" -i 5 -j 9 -stack
echo 'colour around city'
colour.exe -input "inFolder/city.txt" -output "outFolder/city115.txt" -i 1 -j 15 -recursive
echo 'colour top'
colour.exe -input "inFolder/small-5by10.txt" -output "outFolder/small-5by10.txt" -i 1 -j 1 -queue
echo 'colour mound'
colour.exe -input "inFolder/small-5by10.txt" -output "outFolder/small-5by101.txt" -i 4 -j 9 -recursive
