#!/bin/bash

mkdir -p /root/data/rgb1
mkdir -p /root/data/rgb2

num=300
cnt_rgb=0

while :
do

num_rgb1=$(ls /root/data/rgb1 | wc -l)
num_rgb2=$(ls /root/data/rgb2 | wc -l)


if [ "$num_rgb1" = "$num" ]
then
        cnt_rgb=$((cnt_rgb+1))
        echo "rgb1 compressing - ${cnt_rgb}"
        /usr/bin/time --format='Took %e seconds' zip -9qr /root/data/rgb$cnt_rgb.zip /root/data/rgb1
        rm /root/data/rgb1/*.jpeg
        echo "rgb1 deleted"
fi

if [ "$num_rgb2" = "$num" ]
then
        cnt_rgb=$((cnt_rgb+1))
        echo "rgb2 compressing - ${cnt_rgb}"
        /usr/bin/time --format='Took %e seconds' zip -9qr /root/data/rgb$cnt_rgb.zip /root/data/rgb2
        rm /root/data/rgb2/*.jpeg
        echo "rgb2 deleted"
fi
    
sleep 0.01

done








