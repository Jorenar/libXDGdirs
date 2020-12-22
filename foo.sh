#!/usr/bin/env sh

if [ -n "$UNCRUSTIFY_CONFIG" ]; then
    dir="$(dirname $UNCRUSTIFY_CONFIG)"
else
    dir="$HOME/.uncrustify"
fi

cfg=".uncrustify"

for f in "base" "kr" "mb"; do
    cfgs="$cfgs $dir/$f"
done

cat $cfgs > "$cfg"
