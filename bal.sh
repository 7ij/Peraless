#!/usr/bin/bash
windowid=$(xdotool getwindowfocus)
# sleep 0.05 &&
# xdotool windowactivate  --sync $windowid key --clearmodifiers "ctrl+a"
xdotool windowactivate  --sync $windowid key --clearmodifiers "ctrl+v"

 
