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
badd +27 src/main.c
badd +5 Makefile
badd +117 libft/libft.h
badd +22 libft/ft_split.c
badd +14 libft/ft_count_word.c
badd +48 libft/Makefile
badd +62 include/push_swap.h
badd +2 term://~/hive/pushswap//350770:/usr/bin/fish
badd +44 src/quicksort.c
badd +90 TODO.md
badd +29 libft/ft_atoi.c
badd +95 src/errors.c
badd +63 src/parser.c
badd +29 src/utils.c
badd +22 libft/ft_calloc.c
badd +1 src/util
badd +19 libft/ft_sort.c
badd +1 src/parser.csrc/operations.c
badd +13 src/stack_op.c
badd +5 libft/ft_memmove.c
badd +119 src/algo.c
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
badd +12 test
badd +14 src/algo_helper.c
badd +18 src/post_algo.c
badd +14 src/tuning.c
badd +23 src/minisort.c
badd +1 src/utils
badd +63 README.md
badd +1 exception.txt
argglobal
%argdel
$argadd src/main.c
set stal=2
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
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 137 + 137) / 274)
exe 'vert 2resize ' . ((&columns * 136 + 137) / 274)
argglobal
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
let s:l = 28 - ((27 * winheight(0) + 35) / 70)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 28
normal! 05|
wincmd w
argglobal
if bufexists(fnamemodify("src/parser.c", ":p")) | buffer src/parser.c | else | edit src/parser.c | endif
if &buftype ==# 'terminal'
  silent file src/parser.c
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
let s:l = 63 - ((37 * winheight(0) + 35) / 70)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 63
normal! 017|
wincmd w
2wincmd w
exe 'vert 1resize ' . ((&columns * 137 + 137) / 274)
exe 'vert 2resize ' . ((&columns * 136 + 137) / 274)
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
exe 'vert 1resize ' . ((&columns * 136 + 137) / 274)
exe 'vert 2resize ' . ((&columns * 137 + 137) / 274)
argglobal
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
let s:l = 62 - ((29 * winheight(0) + 35) / 70)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 62
normal! 066|
wincmd w
argglobal
if bufexists(fnamemodify("Makefile", ":p")) | buffer Makefile | else | edit Makefile | endif
if &buftype ==# 'terminal'
  silent file Makefile
endif
balt test
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
let s:l = 7 - ((6 * winheight(0) + 35) / 70)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 7
normal! 039|
wincmd w
exe 'vert 1resize ' . ((&columns * 136 + 137) / 274)
exe 'vert 2resize ' . ((&columns * 137 + 137) / 274)
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
