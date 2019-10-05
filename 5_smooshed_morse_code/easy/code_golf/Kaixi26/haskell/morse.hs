import Data.List
k=["",".","-"]
main=interact$concat.map(maybe""id.flip lookup(zip"eiasurwhvf-l pjtnmdkgobxcyzq.-"$nub[a++b++c++d|a<-tail k,b<-k,c<-k,d<-k]))
