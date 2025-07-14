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
badd +47 src/main.c
badd +18 Makefile
badd +107 libft/libft.h
badd +14 libft/ft_split.c
badd +14 libft/ft_count_word.c
badd +3 libft/Makefile
badd +81 include/push_swap.h
badd +2 term://~/hive/pushswap//350770:/usr/bin/fish
badd +44 src/quicksort.c
badd +23 TODO.md
badd +30 libft/ft_atoi.c
badd +81 src/errors.c
badd +78 src/parser.c
badd +17 src/utils.c
badd +22 libft/ft_calloc.c
badd +1 src/util
badd +82 libft/ft_sort.c
badd +1 src/parser.csrc/operations.c
badd +44 src/stack_op.c
badd +11 libft/ft_memmove.c
badd +11 term://~/hive/pushswap//1067021:/bin/zsh
badd +8 src/algo.c
argglobal
%argdel
$argadd src/main.c
set stal=2
tabnew +setlocal\ bufhidden=wipe
tabnew +setlocal\ bufhidden=wipe
tabrewind
edit src/main.c
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd _ | wincmd |
split
1wincmd k
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
exe 'vert 1resize ' . ((&columns * 136 + 137) / 274)
exe '2resize ' . ((&lines * 55 + 36) / 73)
exe 'vert 2resize ' . ((&columns * 137 + 137) / 274)
exe '3resize ' . ((&lines * 14 + 36) / 73)
exe 'vert 3resize ' . ((&columns * 137 + 137) / 274)
argglobal
balt src/algo.c
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
let s:l = 47 - ((46 * winheight(0) + 35) / 70)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 47
normal! 038|
wincmd w
argglobal
if bufexists(fnamemodify("src/stack_op.c", ":p")) | buffer src/stack_op.c | else | edit src/stack_op.c | endif
if &buftype ==# 'terminal'
  silent file src/stack_op.c
endif
balt src/algo.c
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
let s:l = 41 - ((30 * winheight(0) + 27) / 55)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 41
normal! 0
wincmd w
argglobal
if bufexists(fnamemodify("TODO.md", ":p")) | buffer TODO.md | else | edit TODO.md | endif
if &buftype ==# 'terminal'
  silent file TODO.md
endif
balt src/utils.c
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
let s:l = 51 - ((7 * winheight(0) + 7) / 14)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 51
normal! 0
wincmd w
exe 'vert 1resize ' . ((&columns * 136 + 137) / 274)
exe '2resize ' . ((&lines * 55 + 36) / 73)
exe 'vert 2resize ' . ((&columns * 137 + 137) / 274)
exe '3resize ' . ((&lines * 14 + 36) / 73)
exe 'vert 3resize ' . ((&columns * 137 + 137) / 274)
tabnext
edit include/push_swap.h
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
exe '1resize ' . ((&lines * 45 + 36) / 73)
exe 'vert 1resize ' . ((&columns * 136 + 137) / 274)
exe '2resize ' . ((&lines * 24 + 36) / 73)
exe 'vert 2resize ' . ((&columns * 136 + 137) / 274)
exe 'vert 3resize ' . ((&columns * 137 + 137) / 274)
argglobal
balt src/quicksort.c
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
let s:l = 81 - ((40 * winheight(0) + 22) / 45)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 81
normal! 029|
wincmd w
argglobal
if bufexists(fnamemodify("src/utils.c", ":p")) | buffer src/utils.c | else | edit src/utils.c | endif
if &buftype ==# 'terminal'
  silent file src/utils.c
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
let s:l = 12 - ((11 * winheight(0) + 12) / 24)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 12
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
let s:l = 18 - ((17 * winheight(0) + 35) / 70)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 18
normal! 0
wincmd w
exe '1resize ' . ((&lines * 45 + 36) / 73)
exe 'vert 1resize ' . ((&columns * 136 + 137) / 274)
exe '2resize ' . ((&lines * 24 + 36) / 73)
exe 'vert 2resize ' . ((&columns * 136 + 137) / 274)
exe 'vert 3resize ' . ((&columns * 137 + 137) / 274)
tabnext
edit libft/ft_sort.c
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
exe 'vert 1resize ' . ((&columns * 111 + 137) / 274)
exe 'vert 2resize ' . ((&columns * 162 + 137) / 274)
argglobal
balt libft/ft_memmove.c
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
let s:l = 82 - ((46 * winheight(0) + 35) / 70)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 82
normal! 029|
wincmd w
argglobal
if bufexists(fnamemodify("libft/libft.h", ":p")) | buffer libft/libft.h | else | edit libft/libft.h | endif
if &buftype ==# 'terminal'
  silent file libft/libft.h
endif
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
let s:l = 107 - ((0 * winheight(0) + 35) / 70)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 107
normal! 06|
wincmd w
exe 'vert 1resize ' . ((&columns * 111 + 137) / 274)
exe 'vert 2resize ' . ((&columns * 162 + 137) / 274)
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
