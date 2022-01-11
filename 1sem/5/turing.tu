0, ,<,searchStart1

searchStart1,1,<,searchStart1
searchStart1,0,<,searchStart1
searchStart1, ,*,searchStart2

searchStart2,*,<,searchStart2
searchStart2,1,<,searchStart2
searchStart2,0,<,searchStart2
searchStart2, ,>,copy

copy,1,!,copy1
copy,0,!,copy0
copy,*,!,copy*
copy, , ,gotoFirst

copyNext,1,>,copy
copyNext,0,>,copy
copyNext, ,>,copy

copy1,!,>,copy1
copy1,1,>,copy1
copy1,0,>,copy1
copy1,*,>,copy1
copy1, ,>,paste1

copy0,!,>,copy0
copy0,1,>,copy0
copy0,0,>,copy0
copy0,*,>,copy0
copy0, ,>,paste0

copy*,!,>,copy*
copy*,1,>,copy*
copy*,0,>,copy*
copy*,*,>,copy*
copy*, ,>,paste*

paste1, ,1,bringBack1
paste1,1,>,paste1
paste1,0,>,paste1
paste1,*,>,paste1

paste0, ,0,bringBack0
paste0,1,>,paste0
paste0,0,>,paste0
paste0,*,>,paste0

paste*, ,*,bringBack*
paste*,1,>,paste*
paste*,0,>,paste*

bringBack1,1,<,bringBack1
bringBack1,0,<,bringBack1
bringBack1, ,<,bringBack1
bringBack1,*,<,bringBack1
bringBack1,!,1,copyNext

bringBack0,1,<,bringBack0
bringBack0,0,<,bringBack0
bringBack0, ,<,bringBack0
bringBack0,*,<,bringBack0
bringBack0,!,0,copyNext

bringBack*,*,<,bringBack*
bringBack*,1,<,bringBack*
bringBack*,0,<,bringBack*
bringBack*, ,<,bringBack*
bringBack*,!, ,copyNext

gotoFirst, ,>,gotoFirst
gotoFirst,1,>,gotoFirst
gotoFirst,0,>,gotoFirst
gotoFirst,*,<,checkFirst

gotoFirstEnd, ,>,gotoFirstEnd
gotoFirstEnd,1,>,gotoFirstEnd
gotoFirstEnd,0,>,gotoFirstEnd
gotoFirstEnd,*,*,checkSecond


gotoSecond,1,>,gotoSecond
gotoSecond,0,>,gotoSecond
gotoSecond,*,>,checkSecond
gotoSecond, ,<,decreaseSecond

gotoSecondEnd,1,>,gotoSecondEnd
gotoSecondEnd,0,>,gotoSecondEnd
gotoSecondEnd, ,<,decreaseSecond

checkFirst,*,<,checkFirst
checkFirst,0,<,checkFirst
checkFirst,1,1,gotoFirstEnd
checkFirst, , ,clearFirst

checkSecond,*,>,checkSecond
checkSecond,0,>,checkSecond
checkSecond,1,1,gotoSecondEnd
checkSecond, , ,clearSecond

clearFirst, ,>,clearFirst
clearFirst,0, ,clearFirst
clearFirst,*, ,finish

clearSecond, ,<,clearSecond
clearSecond,*, ,finish
clearSecond,0, ,clearSecond

decreaseSecond,1,0,goto*
decreaseSecond,0,1,decreaseSecond1
decreaseSecond1,1,<,decreaseSecond

decreaseFirst,1,0,goto**
decreaseFirst,0,1,decreaseFirst1
decreaseFirst1,1,<,decreaseFirst

goto*,0,<,goto*
goto*,1,<,goto*
goto*,*,<,decreaseFirst

goto**,0,>,goto**
goto**,1,>,goto**
goto**,*,*,checkFirst

finish,0,0,finish
finish,1,1,finish
finish, , ,finish
finish,*,*,finish
