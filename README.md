# minishell

## Overview

**-Basic Command:** cd, pwd, env, exit, unset, export, echo (all other bash commands are implemented with execv)  
**-Cmd history:** arrow key up/down  
**-Single and double Quotes**  
**-Redirections:** < (input), > (trunc), >> (append) and << (heredoc)  
**-Pipes:** single and multible pipe(s), combination with redirections possible  
**-Environment Variables**  
**-Signals:** ctrl-C, ctrl-D and ctrl-\

## Setup

### Install

`make`

### Uninstall

실행파일까지 모두 삭제 : `make fclean`

obj 파일만 삭제 : `make clean`

### Execute
`./minishell`

## 활용 외부 Library

[Termcap](https://www.gnu.org/software/termutils/manual/termcap-1.3/html_mono/termcap.html)

