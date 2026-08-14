# Team Alligator — Software Synthesizer Project

## Gap Analysis and Delivery Strategy

**Course project:** Software synthesizer in openFrameworks  
**Team:** Alligator — members `s-001083` and `s-01130`  
**Deadline:** 25 August 2026, 23:55 UTC  
**Planning window:** 14–25 August 2026  
**Expected effort:** approximately 12 hours during Weeks 5–6

## 1. Executive recommendation

Build a small but polished **Alligator Swamp Synth**: a three-voice software instrument with keyboard control, mouse-based sound shaping, and a functional waveform/spectrum display. Keep the audio engine intentionally modest so the team can spend enough time on OOP quality, usability, testing, documentation, Yellowdig evidence, and packaging.

The project should demonstrate:

- three recognisably different sounds;
- interaction through both keyboard and mouse;
- purposeful sound visualisation;
- a clean object-oriented design using inheritance and composition;
- a reproducible build and a complete submission package;
- transparent collaboration and AI-use documentation.

Do not make sampling a core dependency. Add one short sample pad only if the required synthesizer, documentation, posts, and packaging are already complete.

## 2. Gap analysis

| Area | Current gap | Required decision or evidence | Priority |
|---|---|---|---|
| Product concept | No defined synthesizer identity or interaction model | Approve the Alligator Swamp Synth concept and three sound voices | High |
| Functional scope | “Three sounds” is required, but their synthesis methods are unspecified | Implement sine/subtractive lead, FM bell, and noise percussion | High |
| openFrameworks setup | Target OS, OF version, compiler, and audio-device assumptions are unknown | Record both developers’ environments and confirm a clean starter build | High |
| OOP structure | The assignment requires at least two class relationships | Use inheritance and composition, and explain both in the report | High |
| Team ownership | No division of work or integration rule is defined | Assign primary owners while requiring peer review on every pull request | High |
| Process evidence | Each member needs at least seven substantive posts/comments | Begin the dated Yellowdig schedule immediately; do not backfill everything at the end | Critical |
| Course tagging | Brief says “Project 1,” while the submission page says “Project 2” | Ask the tutor which tag is authoritative; until clarified, include both “Project 1” and “Team Alligator” in post text | Medium |
| Documentation | PDF manual and learning log are not yet drafted | Work directly in the supplied Lab Report template from day one | High |
| GitHub evidence | Repository/link and contribution workflow are not yet established | Create a shared repo, issues, protected main branch, pull requests, and release tag | High |
| AI disclosure | Prompts and AI-assessment level must be declared | Maintain an AI-use log containing prompt, purpose, output used, human verification, and final decision | High |
| Packaging | Final ZIP rules and contents are not defined | Use a scripted clean package that contains source/assets/PDF/learning log and excludes build/cache files | High |
| Submission control | A team response cannot be edited after submission | One member uploads; the other independently verifies the ZIP before final submission | Critical |

## 3. Proposed product

### 3.1 Core user experience

The application opens to a single instrument screen. The user chooses one of three voices, plays notes using the computer keyboard, and moves the mouse across an XY control area:

- horizontal mouse movement changes filter cutoff or timbral brightness;
- vertical mouse movement changes resonance, modulation depth, or envelope length;
- the current waveform and a simple spectrum or amplitude history are displayed;
- voice name, active note, frequency, volume, and control values are always visible.

### 3.2 Three required sounds

1. **Swamp Lead** — sine/saw-style oscillator with an amplitude envelope and mouse-controlled brightness.
2. **Gator Bell** — two-operator FM voice with mouse-controlled modulation index.
3. **Marsh Hit** — short filtered-noise percussion voice with mouse-controlled decay.

These are technically distinct, audibly recognisable, and achievable within the 12-hour workload.

### 3.3 Controls

- `1`, `2`, `3`: select voice.
- `A S D F G H J K`: play a mapped musical scale.
- Mouse X/Y: shape the selected voice.
- Space: stop all notes/panic.
- `V`: switch visualisation mode.
- Optional: mouse click on three on-screen pads to trigger sounds without the keyboard.

## 4. OOP design

### Relationship 1 — inheritance

Create an abstract `SynthVoice` base class that defines a common interface such as `noteOn`, `noteOff`, `renderSample`, `setParameter`, and `getName`. Implement three subclasses:

- `LeadVoice`
- `FMBellVoice`
- `NoisePercussionVoice`

**Why:** all voices share playable behaviour, but each generates audio differently. Polymorphism lets the engine switch voices without knowing their internal synthesis method.

### Relationship 2 — composition

`SynthEngine` owns the voice objects, envelope/state data, and mixer. `ofApp` owns a `SynthEngine`, `InputMapper`, and `AudioVisualizer`.

**Why:** these objects are meaningful parts of the application and their lifecycles belong to the containing object. Composition keeps UI, input, audio, and visualisation responsibilities separate.

### Suggested file structure

```text
src/
  main.cpp
  ofApp.h
  ofApp.cpp
  audio/SynthVoice.h
  audio/LeadVoice.h/.cpp
  audio/FMBellVoice.h/.cpp
  audio/NoisePercussionVoice.h/.cpp
  audio/SynthEngine.h/.cpp
  ui/InputMapper.h/.cpp
  ui/AudioVisualizer.h/.cpp
bin/data/
  sounds/                 # optional sample only
docs/
  screenshots/
  ai-use-log.md
scripts/
  verify-project.sh
  package-submission.sh
README.md
```

## 5. Team collaboration model

Use shared ownership rather than splitting the application into two isolated halves.

### Suggested primary ownership

**Oche / `s-001083`**

- product definition and interaction design;
- `ofApp`, `InputMapper`, and visual presentation;
- manual, learning-log consolidation, packaging, and final submission control.

**Hala / `s-01130`**

- `SynthVoice` hierarchy and audio-engine implementation;
- envelopes, FM/noise voice behaviour, audio safety, and core tests;
- technical OOP explanation and audio-engine screenshots/evidence.

### Shared responsibilities

- each issue has one owner and one reviewer;
- no direct work on `main`;
- branch names: `feature/lead-voice`, `feature/visualizer`, `docs/manual`, etc.;
- each pull request states what changed, how it was tested, and includes a screenshot or short recording where useful;
- the other member reviews before merge;
- both members test the release candidate on their own machine;
- both members make at least seven distinct Yellowdig contributions.

## 6. GitHub workflow

1. Create the repository and add both members.
2. Add a concise README with setup, controls, architecture, and build instructions.
3. Create milestones: `MVP`, `Release Candidate`, and `Submission`.
4. Create issues for environment setup, each voice, input, visualisation, documentation, testing, packaging, and AI disclosure.
5. Use pull requests and peer review for all substantial changes.
6. Tag the verified final commit as `v1.0-submission`.
7. Build the submission ZIP from that tag, not from an uncommitted working directory.

## 7. Yellowdig process-documentation strategy

Each member needs **at least seven substantive posts or comments**. Likes and emojis do not count as sufficient interaction. Contributions should show decisions, intermediate evidence, obstacles, learning, or peer feedback. Do not duplicate a teammate’s post; comment with a different perspective or new evidence.

### Recommended calendar

| Date | Lead post | Teammate contribution | Evidence |
|---|---|---|---|
| 14 Aug | Project concept and success criteria | Comment on scope and risks | Sketch or feature list |
| 16 Aug | openFrameworks audio setup | Comment with second-machine setup findings | Build screenshot/error |
| 18 Aug | OOP voice hierarchy | Comment explaining composition and review feedback | Class diagram/code excerpt |
| 20 Aug | First two voices demonstrated | Comment comparing sound behaviour | Short screencast/waveform |
| 22 Aug | Interaction and visualisation | Comment on usability change | UI screenshot |
| 24 Aug | Integration obstacle and resolution | Comment with test evidence | Error/fix/PR link |
| 25 Aug | Release candidate reflection | Comment with independent ZIP verification | Final screenshot/stats/repo link |

If work is bundled into fewer days, post during the actual work sessions, but maintain a truthful sequence.

### Ready-to-adapt post prompts

**Post 1 — scope**  
“Team Alligator has defined our synthesizer MVP: three distinct voices, keyboard and XY mouse control, and a functional waveform/spectrum display. We deliberately kept sampling optional so we can prioritise stable audio, OOP quality, and documentation. Our next question is how best to keep the audio thread safe while updating parameters from user input.”

**Post 2 — setup obstacle**  
“Today I configured openFrameworks and tested the audio callback. The main obstacle was [error]. The cause was [cause], and we resolved it by [fix]. The screenshot shows the first stable output. My next step is to isolate synthesis logic from `ofApp`.”

**Post 3 — OOP**  
“We introduced a `SynthVoice` base class with specialised lead, FM, and percussion subclasses. This inheritance relationship gives the engine one interface for different synthesis algorithms. We also use composition: `ofApp` contains the engine, input mapper, and visualizer. This has already reduced UI/audio coupling.”

**Post 4 — intermediate sound result**  
“The lead and FM voices now produce clearly different timbres. The attached clip shows the same note played through both. We adjusted [parameter] because [observation]. We still need to handle clipping when notes overlap.”

**Post 5 — interaction**  
“Mouse X/Y now changes timbre in real time. We chose this over adding more keyboard shortcuts because the relationship between gesture and sound is easier to explore. The display shows the parameter values so the visualisation communicates state rather than serving as decoration.”

**Post 6 — test/fix**  
“During integration we reproduced [bug] using [steps]. The issue came from [cause]. After the fix, both team members tested [cases]. The PR and before/after evidence are linked below.”

**Post 7 — reflection**  
“Our release candidate meets the required three sounds and demonstrates inheritance plus composition. The most important lesson was [lesson]. If we continued, we would improve [bounded future enhancement]. The repository, final controls, and verification evidence are linked here.”

## 8. Development and release plan

### Phase 1 — definition and setup (14–16 Aug)

- approve scope and controls;
- confirm OF version and target platforms;
- create repo, issues, branches, and report template;
- prove that a minimal audio callback produces safe output;
- publish the first two Yellowdig contributions per member.

### Phase 2 — audio MVP (17–20 Aug)

- implement `SynthVoice` interface and three subclasses;
- implement note mapping and amplitude envelopes;
- prevent clipping using conservative gain/limiting;
- demonstrate three audibly distinct sounds;
- capture intermediate evidence and posts.

### Phase 3 — interaction and visualisation (20–22 Aug)

- implement mouse XY mapping and on-screen controls;
- implement waveform/amplitude display and optional spectrum;
- add status text and panic control;
- conduct peer usability review.

### Phase 4 — integration, documentation, and QA (23–24 Aug)

- complete supplied Lab Report template;
- explain inheritance and composition with a class diagram;
- complete manual, AI-use log, screenshots, learning log, and GitHub statistics;
- build on both machines;
- fix only submission-blocking defects after code freeze.

### Phase 5 — release and submission (25 Aug)

- merge verified pull requests;
- tag `v1.0-submission`;
- run packaging script;
- independently inspect ZIP contents and test extraction/build;
- post final Yellowdig reflections;
- upload the single ZIP and verify the LMS preview;
- submit only after both team members approve, because the response cannot be edited afterward.

## 9. Testing and acceptance criteria

The project is complete only when:

- the app launches without missing assets;
- each of the three voice selections produces a distinct sound;
- all mapped keys trigger the expected notes;
- mouse movement changes the displayed and audible parameter;
- the panic control stops active sound;
- output does not exhibit persistent clipping or runaway volume;
- visualisation responds to generated audio and has a stated purpose;
- OOP relationships are visible in code and correctly explained in the PDF;
- a clean clone/build succeeds using documented steps;
- the ZIP contains required source/assets, PDF manual, and learning log;
- the learning log shows at least seven contributions per member;
- the GitHub link and contribution statistics are included;
- AI prompts, uses, human decisions, and framework level are disclosed.

## 10. Documentation package

### Project PDF/manual

Include:

1. project concept and goals;
2. installation/build prerequisites;
3. controls and usage instructions;
4. screenshots of meaningful interface states;
5. architecture and class diagram;
6. explanation of inheritance and composition;
7. synthesis methods for the three sounds;
8. obstacles, fixes, tests, limitations, and future work;
9. team contributions;
10. AI-use declaration.

### Learning log

Use the supplied template and include:

- chronological post/comment excerpts;
- dates, author, link, and screenshot where practical;
- Yellowdig statistics for each member;
- GitHub repository link;
- short reflection on collaboration and learning.

### AI-use log

For every material use, record:

- date;
- tool;
- sample prompt;
- purpose (brainstorming, explanation, debugging, review, etc.);
- what the team accepted, changed, or rejected;
- how the result was tested or verified;
- the selected AI Assessment Scale level and justification.

AI should support decisions and learning. It must not replace the team’s implementation, understanding, or documentation.

## 11. Packaging and deployment scripts

Prepare two small scripts:

- `verify-project.sh`: confirms required `.h/.cpp`, assets, PDF, learning log, README, and repository metadata exist; scans for accidental secrets and oversized build artefacts.
- `package-submission.sh`: creates a clean staging directory and generates `Team_Alligator_Software_Synthesizer.zip` from the verified release tag.

The ZIP should exclude `.git`, IDE caches, temporary recordings, local absolute paths, compiler caches, and unnecessary build outputs. Include the generated openFrameworks project files only where required for the tutor to open/build the project.

## 12. Immediate approval decisions

Before implementation, confirm:

1. approve or adjust the **Alligator Swamp Synth** concept;
2. identify which member ID belongs to Oche and which belongs to Hala;
3. provide the GitHub repository or authorise creation of one;
4. provide the Lab Report template file;
5. confirm both development operating systems and installed openFrameworks versions;
6. clarify with the tutor whether Yellowdig should be tagged “Project 1” or “Project 2.”

Once approved, implementation should begin with repository setup, the class skeleton, the minimal audio callback, and the first Yellowdig post—not with optional visual effects or sampling.
