#!/bin/bash

mkdir -p /home/lsi04/data/rgb1
mkdir -p /home/lsi04/data/rgb2

num=300
cnt_rgb=0

while :
do

num_rgb1=$(ls /home/lsi04/data/rgb1 | wc -l)
num_rgb2=$(ls /home/lsi04/data/rgb2 | wc -l)


if [ "$num_rgb1" = "$num" ]
then
        cnt_rgb=$((cnt_rgb+1))
        echo "rgb1 compressing - ${cnt_rgb}"
        /usr/bin/time --format='Took %e seconds' zip -9qr /home/lsi04/data/rgb$cnt_rgb.zip /home/lsi04/data/rgb1
        rm /home/lsi04/data/rgb1/*.jpeg
        echo "rgb1 deleted"
fi

if [ "$num_rgb2" = "$num" ]
then
        cnt_rgb=$((cnt_rgb+1))
        echo "rgb2 compressing - ${cnt_rgb}"
        /usr/bin/time --format='Took %e seconds' zip -9qr /home/lsi04/data/rgb$cnt_rgb.zip /home/lsi04/data/rgb2
        rm /home/lsi04/data/rgb2/*.jpeg
        echo "rgb2 deleted"
fi
    
sleep 0.01

done








