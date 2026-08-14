#!/usr/bin/env bash
set -euo pipefail

root="$(cd "$(dirname "$0")/.." && pwd)"
required=(
  README.md
  src/audio/SynthVoice.h
  src/audio/SynthEngine.h
  docs/yellowdig-log.md
  docs/ai-use-log.md
)

for path in "${required[@]}"; do
  test -s "$root/$path" || { echo "MISSING: $path"; exit 1; }
done

if grep -RIlE 'BEGIN [A-Z ]*PRIVATE KEY|Authorization:[[:space:]]*Bearer|client_secret' "$root" \
  --exclude-dir=.git \
  --exclude='verify-project.sh'; then
  echo "STOP: possible secret found"
  exit 1
fi

echo "Static project checks passed."
echo "TODO before submission: compile on both machines and verify manual/learning-log PDFs."
