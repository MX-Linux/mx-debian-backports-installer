#!/bin/bash

DIR=/tmp/mx-debian-backports-installer

# get package list based on architecture

if [ -f $DIR/packagelist.txt ]; then
	rm -f $DIR/packagelist.txt
fi

if [ -d $DIR ]; then
	echo "directory found"
	else
	mkdir -p $DIR
fi

arch=$(dpkg --print-architecture)

if [ "$arch" = "i386" ]; then
	wget ftp://ftp.us.debian.org/debian/dists/jessie-backports/main/binary-i386/Packages.gz -O $DIR/mainPackages.gz
	wget ftp://ftp.us.debian.org/debian/dists/jessie-backports/contrib/binary-i386/Packages.gz -O $DIR/contribPackages.gz
	wget ftp://ftp.us.debian.org/debian/dists/jessie-backports/non-free/binary-i386/Packages.gz -O $DIR/nonfreePackages.gz

else
	wget ftp://ftp.us.debian.org/debian/dists/jessie-backports/main/binary-amd64/Packages.gz -O $DIR/mainPackages.gz
	wget ftp://ftp.us.debian.org/debian/dists/jessie-backports/contrib/binary-amd64/Packages.gz -O $DIR/contribPackages.gz
	wget ftp://ftp.us.debian.org/debian/dists/jessie-backports/non-free/binary-amd64/Packages.gz -O $DIR/nonfreePackages.gz
fi

#unpack Packages.gz
gzip -df $DIR/mainPackages.gz 
gzip -df $DIR/contribPackages.gz 
gzip -df $DIR/nonfreePackages.gz 

#build short package description file

IFS=$'\n'

declare -a packagename
declare -a packageversion
declare -a packagedescrip

packagename=(`cat $DIR/*Packages |awk '/Package:/ && !/-Package/'|cut -d " " -f2`)
packageversion=(`cat $DIR/*Packages |awk '/Version:/ && !/-Version/'|cut -d " " -f2`)
packagedescrip=(`cat $DIR/*Packages |awk '/Description:/ && !/-Description/'|cut -d ":" -f2`)

count=$(echo ${#packagename[@]}) 
countversion=$(echo ${#packageversion[@]}) 
countdescrip=$(echo ${#packagedescrip[@]}) 
echo $count Packages
echo $countversion Version
echo $countdescrip Descriptions


i="0"
while [ "$i" -lt "$count" ]
do
	echo "${packagename[i]} ${packageversion[i]} ${packagedescrip[i]}">>$DIR/packagelist.txt
	i=$[$i+1]
done

rm -f $DIR/*Packages.gz
rm -f $DIR/*Packages