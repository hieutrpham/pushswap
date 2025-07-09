let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/hive/pushswap
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
let s:shortmess_save = &shortmess
if &shortmess =~ 'A'
  set shortmess=aoOA
else
  set shortmess=aoO
endif
badd +16 src/main.c
badd +15 Makefile
badd +16 libft/libft.h
badd +14 libft/ft_split.c
badd +14 libft/ft_count_word.c
badd +53 libft/Makefile
badd +45 include/push_swap.h
badd +2 term://~/hive/pushswap//350770:/usr/bin/fish
badd +34 src/quicksort.c
badd +21 TODO.md
badd +1 libft/ft_atoi.c
badd +11 src/errors.c
badd +25 src/parser.c
badd +18 src/utils.c
badd +2 libft/ft_calloc.c
badd +1 src/util
argglobal
%argdel
$argadd src/main.c
set stal=2
tabnew +setlocal\ bufhidden=wipe
tabnew +setlocal\ bufhidden=wipe
tabrewind
edit src/errors.c
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd _ | wincmd |
split
1wincmd k
wincmd w
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe '1resize ' . ((&lines * 49 + 32) / 65)
exe 'vert 1resize ' . ((&columns * 119 + 120) / 240)
exe '2resize ' . ((&lines * 12 + 32) / 65)
exe 'vert 2resize ' . ((&columns * 119 + 120) / 240)
exe 'vert 3resize ' . ((&columns * 120 + 120) / 240)
argglobal
balt src/main.c
setlocal foldmethod=manual
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
silent! normal! zE
let &fdl = &fdl
let s:l = 52 - ((38 * winheight(0) + 24) / 49)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 52
normal! 0
wincmd w
argglobal
if bufexists(fnamemodify("TODO.md", ":p")) | buffer TODO.md | else | edit TODO.md | endif
if &buftype ==# 'terminal'
  silent file TODO.md
endif
balt src/main.c
setlocal foldmethod=manual
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
silent! normal! zE
let &fdl = &fdl
let s:l = 13 - ((5 * winheight(0) + 6) / 12)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 13
normal! 03|
wincmd w
argglobal
if bufexists(fnamemodify("src/parser.c", ":p")) | buffer src/parser.c | else | edit src/parser.c | endif
if &buftype ==# 'terminal'
  silent file src/parser.c
endif
balt src/errors.c
setlocal foldmethod=manual
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
silent! normal! zE
let &fdl = &fdl
let s:l = 1 - ((0 * winheight(0) + 31) / 62)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
3wincmd w
exe '1resize ' . ((&lines * 49 + 32) / 65)
exe 'vert 1resize ' . ((&columns * 119 + 120) / 240)
exe '2resize ' . ((&lines * 12 + 32) / 65)
exe 'vert 2resize ' . ((&columns * 119 + 120) / 240)
exe 'vert 3resize ' . ((&columns * 120 + 120) / 240)
tabnext
edit include/push_swap.h
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe '1resize ' . ((&lines * 61 + 32) / 65)
exe 'vert 1resize ' . ((&columns * 120 + 120) / 240)
exe '2resize ' . ((&lines * 61 + 32) / 65)
exe 'vert 2resize ' . ((&columns * 119 + 120) / 240)
argglobal
balt Makefile
setlocal foldmethod=manual
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
silent! normal! zE
let &fdl = &fdl
let s:l = 34 - ((32 * winheight(0) + 30) / 61)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 34
normal! 0
wincmd w
argglobal
if bufexists(fnamemodify("Makefile", ":p")) | buffer Makefile | else | edit Makefile | endif
if &buftype ==# 'terminal'
  silent file Makefile
endif
balt include/push_swap.h
setlocal foldmethod=manual
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
silent! normal! zE
let &fdl = &fdl
let s:l = 15 - ((14 * winheight(0) + 30) / 61)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 15
normal! 018|
wincmd w
exe '1resize ' . ((&lines * 61 + 32) / 65)
exe 'vert 1resize ' . ((&columns * 120 + 120) / 240)
exe '2resize ' . ((&lines * 61 + 32) / 65)
exe 'vert 2resize ' . ((&columns * 119 + 120) / 240)
tabnext
edit libft/ft_atoi.c
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe '1resize ' . ((&lines * 61 + 32) / 65)
exe 'vert 1resize ' . ((&columns * 120 + 120) / 240)
exe '2resize ' . ((&lines * 61 + 32) / 65)
exe 'vert 2resize ' . ((&columns * 119 + 120) / 240)
argglobal
balt libft/libft.h
setlocal foldmethod=manual
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
silent! normal! zE
let &fdl = &fdl
let s:l = 30 - ((29 * winheight(0) + 30) / 61)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 30
normal! 0
wincmd w
argglobal
if bufexists(fnamemodify("libft/libft.h", ":p")) | buffer libft/libft.h | else | edit libft/libft.h | endif
if &buftype ==# 'terminal'
  silent file libft/libft.h
endif
balt libft/ft_atoi.c
setlocal foldmethod=manual
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
silent! normal! zE
let &fdl = &fdl
let s:l = 16 - ((15 * winheight(0) + 30) / 61)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 16
normal! 0
wincmd w
exe '1resize ' . ((&lines * 61 + 32) / 65)
exe 'vert 1resize ' . ((&columns * 120 + 120) / 240)
exe '2resize ' . ((&lines * 61 + 32) / 65)
exe 'vert 2resize ' . ((&columns * 119 + 120) / 240)
tabnext 1
set stal=1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0 && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20
let &shortmess = s:shortmess_save
let &winminheight = s:save_winminheight
let &winminwidth = s:save_winminwidth
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
set hlsearch
nohlsearch
let g:this_session = v:this_session
let g:this_obsession = v:this_session
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
