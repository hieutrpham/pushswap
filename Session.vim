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
badd +33 src/main.c
badd +23 Makefile
badd +117 libft/libft.h
badd +22 libft/ft_split.c
badd +14 libft/ft_count_word.c
badd +48 libft/Makefile
badd +120 include/push_swap.h
badd +2 term://~/hive/pushswap//350770:/usr/bin/fish
badd +44 src/quicksort.c
badd +84 TODO.md
badd +29 libft/ft_atoi.c
badd +95 src/errors.c
badd +25 src/parser.c
badd +17 src/utils.c
badd +22 libft/ft_calloc.c
badd +1 src/util
badd +19 libft/ft_sort.c
badd +1 src/parser.csrc/operations.c
badd +108 src/stack_op.c
badd +5 libft/ft_memmove.c
badd +15 src/algo.c
badd +44 libft/ft_math.c
badd +1 libft/mak
badd +47 libft/ft_isany.c
badd +1 libft/is
badd +14 libft/ft_isalnum.c
badd +13 libft/ft_isdigit.c
badd +13 libft/ft_isascii.c
badd +13 libft/ft_isalpha.c
badd +13 libft/ft_isprint.c
badd +45 libft/ft_write.c
badd +15 libft/ft_putchar_fd.c
badd +14 libft/ft_putendl_fd.c
badd +14 libft/ft_putstr_fd.c
badd +11 libft/ft_putnbr_fd.c
badd +5 test
badd +118 src/algo_helper.c
badd +18 src/post_algo.c
badd +14 src/tuning.c
badd +23 src/minisort.c
badd +1 src/utils
badd +62 README.md
badd +1 exception.txt
argglobal
%argdel
$argadd src/main.c
set stal=2
tabnew +setlocal\ bufhidden=wipe
tabrewind
edit src/algo_helper.c
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
exe '1resize ' . ((&lines * 35 + 36) / 73)
exe 'vert 1resize ' . ((&columns * 137 + 137) / 274)
exe '2resize ' . ((&lines * 34 + 36) / 73)
exe 'vert 2resize ' . ((&columns * 137 + 137) / 274)
exe 'vert 3resize ' . ((&columns * 136 + 137) / 274)
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
let s:l = 16 - ((15 * winheight(0) + 17) / 35)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 16
normal! 03|
wincmd w
argglobal
if bufexists(fnamemodify("src/main.c", ":p")) | buffer src/main.c | else | edit src/main.c | endif
if &buftype ==# 'terminal'
  silent file src/main.c
endif
balt TODO.md
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
let s:l = 62 - ((16 * winheight(0) + 17) / 34)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 62
normal! 0
wincmd w
argglobal
if bufexists(fnamemodify("src/algo.c", ":p")) | buffer src/algo.c | else | edit src/algo.c | endif
if &buftype ==# 'terminal'
  silent file src/algo.c
endif
balt exception.txt
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
let s:l = 112 - ((23 * winheight(0) + 35) / 70)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 112
normal! 03|
wincmd w
3wincmd w
exe '1resize ' . ((&lines * 35 + 36) / 73)
exe 'vert 1resize ' . ((&columns * 137 + 137) / 274)
exe '2resize ' . ((&lines * 34 + 36) / 73)
exe 'vert 2resize ' . ((&columns * 137 + 137) / 274)
exe 'vert 3resize ' . ((&columns * 136 + 137) / 274)
tabnext
edit include/push_swap.h
argglobal
balt libft/ft_split.c
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
let s:l = 120 - ((67 * winheight(0) + 35) / 70)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 120
normal! 022|
tabnext 1
set stal=1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0 && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20
let &shortmess = s:shortmess_save
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
