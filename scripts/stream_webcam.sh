#! /bin/bash

B="100K"
F="ogg"
ssh 20369194@ECM-L-D-271-021.uniwa.uwa.edu.au ffmpeg -b $B -an -f video4linux2 \
		-s 320x240 -r 10 -i /dev/video0 -b $B -f $F - \
			| mplayer - -idle -demuxer $F
