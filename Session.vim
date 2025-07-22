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
badd +37 src/main.c
badd +21 Makefile
badd +127 libft/libft.h
badd +14 libft/ft_split.c
badd +14 libft/ft_count_word.c
badd +48 libft/Makefile
badd +113 include/push_swap.h
badd +2 term://~/hive/pushswap//350770:/usr/bin/fish
badd +44 src/quicksort.c
badd +82 TODO.md
badd +30 libft/ft_atoi.c
badd +98 src/errors.c
badd +33 src/parser.c
badd +29 src/utils.c
badd +22 libft/ft_calloc.c
badd +1 src/util
badd +65 libft/ft_sort.c
badd +1 src/parser.csrc/operations.c
badd +49 src/stack_op.c
badd +5 libft/ft_memmove.c
badd +48 src/algo.c
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
badd +109 src/algo_helper.c
badd +30 src/post_algo.c
badd +17 src/tuning.c
argglobal
%argdel
$argadd src/main.c
set stal=2
tabnew +setlocal\ bufhidden=wipe
tabrewind
edit src/tuning.c
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
let s:l = 41 - ((39 * winheight(0) + 35) / 70)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 41
normal! 052|
wincmd w
argglobal
if bufexists(fnamemodify("src/post_algo.c", ":p")) | buffer src/post_algo.c | else | edit src/post_algo.c | endif
if &buftype ==# 'terminal'
  silent file src/post_algo.c
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
let s:l = 41 - ((13 * winheight(0) + 35) / 70)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 41
normal! 010|
wincmd w
2wincmd w
exe 'vert 1resize ' . ((&columns * 136 + 137) / 274)
exe 'vert 2resize ' . ((&columns * 137 + 137) / 274)
tabnext
edit Makefile
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
balt libft/ft_math.c
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
let s:l = 21 - ((20 * winheight(0) + 35) / 70)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 21
normal! 0
wincmd w
argglobal
if bufexists(fnamemodify("include/push_swap.h", ":p")) | buffer include/push_swap.h | else | edit include/push_swap.h | endif
if &buftype ==# 'terminal'
  silent file include/push_swap.h
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
let s:l = 113 - ((35 * winheight(0) + 35) / 70)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 113
normal! 031|
wincmd w
exe 'vert 1resize ' . ((&columns * 137 + 137) / 274)
exe 'vert 2resize ' . ((&columns * 136 + 137) / 274)
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
