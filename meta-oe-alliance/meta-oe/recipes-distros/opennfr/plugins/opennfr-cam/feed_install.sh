#!/bin/bash
OLD="http://dev.nachtfalke.biz/nfr/feeds/6.4_dev"
NEW="http://dev.nachtfalke.biz/nfr/feeds/6.4"
DPATH="/etc/opkg/*.conf"
TFILE="/tmp/out.tmp.$$"
for f in $DPATH
do
  if [ -f $f -a -r $f ]; then
   sed "s|$OLD|$NEW|g" "$f" > $TFILE && mv $TFILE "$f"
  else
   echo "Error: Cannot read $f"
  fi
done

