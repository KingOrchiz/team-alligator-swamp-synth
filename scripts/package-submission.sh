#!/usr/bin/env bash
set -euo pipefail

root="$(cd "$(dirname "$0")/.." && pwd)"
"$root/scripts/verify-project.sh"

manual="$root/docs/Team_Alligator_Project_Manual.pdf"
learning="$root/docs/Team_Alligator_Learning_Log.pdf"
test -s "$manual" || { echo "MISSING: $manual"; exit 1; }
test -s "$learning" || { echo "MISSING: $learning"; exit 1; }

stage="$(mktemp -d)"
trap 'rm -rf "$stage"' EXIT
mkdir -p "$stage/Team_Alligator_Software_Synthesizer"

rsync -a \
  --exclude '.git' \
  --exclude 'obj' \
  --exclude 'bin/*.app' \
  --exclude '*.xcuserstate' \
  "$root/" "$stage/Team_Alligator_Software_Synthesizer/"

(cd "$stage" && zip -qr "$root/Team_Alligator_Software_Synthesizer.zip" Team_Alligator_Software_Synthesizer)
echo "Created: $root/Team_Alligator_Software_Synthesizer.zip"
