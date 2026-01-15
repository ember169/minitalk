_This project has been created as part of the 42 curriculum by lgervet_
_[Subject (pdf)](https://cdn.intra.42.fr/pdf/pdf/185021/en.subject.pdf)_

# Description
<!-- Section that clearly presents the project, including its goal and a brief overview. -->
A high-speed inter-process communication project. The goal is to transmit strings between a client and a server using only UNIX signals.

### Technical prerequisites
- Bit-by-bit transmission via SIGUSR1 (representing 0) and SIGUSR2 (representing 1).
- Instantaneous output. Must handle 100+ characters per second.
- The server must stay alive and handle multiple clients sequentially.

### Bonus features
- ACK System: server sends a signal back to the client for every bit received, preventing data loss.
- Unicode Support: full UTF-8 compatibility.

_NB: `_bonus.c` files are exactly the same as the originals, they've been created exclusively to match with the evaluation requirements._

### Global flowchart
![Flowchart](https://github.com/user-attachments/assets/7a65aefb-11f3-4444-b78b-d071f90144b4)

# Instructions
<!-- section containing any relevant information about compilation, installation, and/or execution. -->
### Compilation and execution
1. `make`
2. `./server` to run server and show its PID
3. `./client [SERVER PID] "String to send"`

_NB: this project was designed to be ran on a little-endian environment._

# Resources
<!-- section listing classic references related to the topic (documentation, articles, tutorials, etc.), as well as a description of how AI was used — specifying for which tasks and which parts of the project. -->

### About signals
- _[Information on signals and their usage](https://sites.uclouvain.be/SystInfo/notes/Theorie/html/Fichiers/fichiers-signaux.html)_
- _[Difference between SIGUSR1 and SIGUSR2](https://stackoverflow.com/questions/27403641/difference-between-sigusr1-and-sigusr2)_
- _[Tips on sending acknowledgment from the server](https://stackoverflow.com/questions/13477714/how-to-send-signal-sigusr1-and-sigusr2-from-parent-to-children)_
- _[Tips on using signals in C](https://thelinuxcode.com/signal_handlers_c_programming_language)_
- _[Example of signals usage](https://github.com/Basel-Dawoud/Send-Receive_LinuxSignals/blob/main/receiver.c)_

### About processes
- _[Documentation on processes](https://www.gnu.org/software/libc/manual/html_node/Processes.html)_
- _[Documentation on `kill()` function](https://www.gnu.org/software/libc/manual/html_node/Signaling-Another-Process.html)_

### About pids
- _[Documentation on `getpid()` function](https://www.man7.org/linux/man-pages/man2/getpid.2.html)_

### About binary operation
- _[Binary representation of a string](https://stackoverflow.com/questions/5666900/converting-c-string-to-binary-representation)_
- _[Assemble a byte in integer](https://stackoverflow.com/questions/12240299/convert-bytes-to-int-uint-in-c)_

### About encoding characters
- _[Documentation on UTF-8 (Wikipedia)](https://fr.wikipedia.org/wiki/UTF-8)_
- _[Documentation on unicode in C](https://thelinuxcode.com/unicode-c/)_
- _[Character encoding conversion table](https://www.utf8-chartable.de/unicode-utf8-table.pl)_
- _[Convert ascii to binary](https://github.com/l-kaushik/Text-to-binary-converter-using-C)_

### About execution time
- _[How to measure execution time on Linux (`time` command )](https://itsfoss.gitlab.io/post/find-the-execution-time-of-a-command-or-process-in-linux/)_

### AI Usage (Gemini 3)
- Better understand how bitwise operators work. Had trouble understanding that `character_int >> 7 & 1` was really just comparing the 7th bit of `character_int` to `1`.
- Helped me troubleshoot a memory allocation issue: `encoded = (char **)malloc((sizeof(char) ...)` instead of `encoded = (char **)malloc((sizeof(char *) ...)` for a 2d array... also gave me a tip: `encoded = (char **)malloc((sizeof(*encoded) ...)`.
- Find other ways than ugly infinite loops to wait for signals: `pause()` and `sigsuspend()`.
- Understand how `signal()` and `sigaction()` are different and made sense of the manual of `sigaction()` for me.
- Debug a signal synchronization issue I had no idea happened.
- Craft a complete unicode stress test:
```
"🚀 [TEST UNICODE] 🚀
🌍 Hello World! - 🇫🇷 Bonjour le monde ! - 🇯🇵 こんにちは世界 - 🇷🇺 Привет, мир!
🔥 Performance Test: ❄️ ❄️ ❄️
Minitalk handles: 
- Symbols: ₪ ₣ ℇ ℟ ℻ ⅀ ↀ ↱ ⇶ ∰ ⊞ ⊠
- Math: ∬ ∑ ∏ ∿ ⊻ ⊕ ⊗
- Greek: α β γ δ ε ζ η θ ι κ λ μ ν ξ ο π ρ σ τ υ φ χ ψ ω
- Mixed: ░▒▓█ █▓▒░ 
--------------------------------------------------
LOREM IPSUM UNICODE EDITION:
Lorem ipsum dolor sit amet, ꞵonsectetur adipiꞑcing elit. 
Σεδ δο ειυσμοδ τεμπορ ιντιδιδυντ υτ λαβορε ετ δολορε μαγνα αλιθυα. 
Ут ενιμ αδ μινιμ υενιαμ, θυις νοστρυδ εχερτιτατιον υλλαμτο λαβορις... 
✅ Fin du test de transmission massive ✅"
```