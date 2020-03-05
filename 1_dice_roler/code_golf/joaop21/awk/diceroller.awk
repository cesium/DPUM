BEGIN{FS="d";srand()}{split("",a);s=0;for(i=1;i<=$1;i++){a[i]=int(($2+1)*rand())+1;s+=a[i]};printf"%s:",s;for(x in a)printf" %s",a[x];print""}
