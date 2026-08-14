# Alligator Swamp Synth

Team Alligator's openFrameworks software-synthesizer project.

## Team

- Oche — `s-001083`
- Hala — `s-01130`

## Approved MVP

- Three distinct synthesizer voices: lead, FM bell, and noise percussion.
- Computer-keyboard note input.
- Mouse XY timbre control and optional clickable pads.
- Purposeful waveform/amplitude visualisation.
- Clean OOP design using inheritance and composition.

## OOP relationships

1. **Inheritance:** `SynthVoice` defines the common playable interface; `LeadVoice`, `FMBellVoice`, and `NoisePercussionVoice` specialise sound generation.
2. **Composition:** `ofApp` contains the `SynthEngine`, `InputMapper`, and `AudioVisualizer`; `SynthEngine` owns its voices.

## Status

Planning and class skeleton only. The team must implement, test, explain, and document the synthesis behaviour. This distinction is intentional and supports the course's AI-use rules.

## Planned controls

| Control | Action |
|---|---|
| `1`, `2`, `3` | Select voice |
| `A S D F G H J K` | Play scale notes |
| Mouse X/Y | Shape the selected voice |
| Space | Stop all sound |
| `V` | Change visualisation mode |

## Development workflow

1. Pick or create a GitHub issue.
2. Create a branch such as `feature/fm-voice`.
3. Implement and test one bounded change.
4. Open a pull request describing the change, test evidence, and Yellowdig evidence opportunity.
5. The other team member reviews before merge.

See [docs/project-plan.md](docs/project-plan.md), [docs/yellowdig-log.md](docs/yellowdig-log.md), and [docs/ai-use-log.md](docs/ai-use-log.md).

## Build prerequisites

To be completed after both team members confirm:

- operating system;
- openFrameworks version;
- compiler/IDE;
- audio-device setup.

## Submission

The verified release will be tagged `v1.0-submission` and packaged with `scripts/package-submission.sh` only after `scripts/verify-project.sh` passes.
