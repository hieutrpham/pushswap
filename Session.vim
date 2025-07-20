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
badd +105 src/main.c
badd +9 Makefile
badd +25 libft/libft.h
badd +14 libft/ft_split.c
badd +14 libft/ft_count_word.c
badd +13 libft/Makefile
badd +75 include/push_swap.h
badd +2 term://~/hive/pushswap//350770:/usr/bin/fish
badd +44 src/quicksort.c
badd +65 TODO.md
badd +30 libft/ft_atoi.c
badd +106 src/errors.c
badd +18 src/parser.c
badd +36 src/utils.c
badd +22 libft/ft_calloc.c
badd +1 src/util
badd +2 libft/ft_sort.c
badd +1 src/parser.csrc/operations.c
badd +109 src/stack_op.c
badd +2 libft/ft_memmove.c
badd +101 src/algo.c
badd +29 libft/ft_math.c
badd +1 libft/mak
badd +47 libft/ft_isany.c
badd +1 libft/is
badd +14 libft/ft_isalnum.c
badd +13 libft/ft_isdigit.c
badd +13 libft/ft_isascii.c
badd +13 libft/ft_isalpha.c
badd +13 libft/ft_isprint.c
badd +1 libft/ft_write.c
badd +15 libft/ft_putchar_fd.c
badd +14 libft/ft_putendl_fd.c
badd +14 libft/ft_putstr_fd.c
badd +11 libft/ft_putnbr_fd.c
badd +3 test
argglobal
%argdel
$argadd src/main.c
set stal=2
tabnew +setlocal\ bufhidden=wipe
tabnew +setlocal\ bufhidden=wipe
tabrewind
edit test
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
exe 'vert 1resize ' . ((&columns * 119 + 120) / 240)
exe 'vert 2resize ' . ((&columns * 120 + 120) / 240)
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
let s:l = 1 - ((0 * winheight(0) + 31) / 62)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
argglobal
if bufexists(fnamemodify("src/algo.c", ":p")) | buffer src/algo.c | else | edit src/algo.c | endif
if &buftype ==# 'terminal'
  silent file src/algo.c
endif
balt src/stack_op.c
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
let s:l = 113 - ((13 * winheight(0) + 31) / 62)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 113
normal! 024|
wincmd w
exe 'vert 1resize ' . ((&columns * 119 + 120) / 240)
exe 'vert 2resize ' . ((&columns * 120 + 120) / 240)
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
exe 'vert 1resize ' . ((&columns * 120 + 120) / 240)
exe 'vert 2resize ' . ((&columns * 119 + 120) / 240)
argglobal
balt src/parser.c
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
let s:l = 9 - ((8 * winheight(0) + 31) / 62)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 9
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
let s:l = 75 - ((18 * winheight(0) + 31) / 62)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 75
normal! 029|
wincmd w
exe 'vert 1resize ' . ((&columns * 120 + 120) / 240)
exe 'vert 2resize ' . ((&columns * 119 + 120) / 240)
tabnext
edit libft/ft_write.c
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
exe '1resize ' . ((&lines * 60 + 32) / 65)
exe 'vert 1resize ' . ((&columns * 58 + 120) / 240)
exe '2resize ' . ((&lines * 29 + 32) / 65)
exe 'vert 2resize ' . ((&columns * 59 + 120) / 240)
exe '3resize ' . ((&lines * 30 + 32) / 65)
exe 'vert 3resize ' . ((&columns * 59 + 120) / 240)
argglobal
balt libft/ft_putchar_fd.c
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
let s:l = 47 - ((43 * winheight(0) + 30) / 60)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 47
normal! 0
wincmd w
argglobal
if bufexists(fnamemodify("libft/libft.h", ":p")) | buffer libft/libft.h | else | edit libft/libft.h | endif
if &buftype ==# 'terminal'
  silent file libft/libft.h
endif
balt libft/Makefile
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
let s:l = 25 - ((9 * winheight(0) + 14) / 29)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 25
normal! 06|
wincmd w
argglobal
if bufexists(fnamemodify("libft/Makefile", ":p")) | buffer libft/Makefile | else | edit libft/Makefile | endif
if &buftype ==# 'terminal'
  silent file libft/Makefile
endif
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
let s:l = 20 - ((10 * winheight(0) + 15) / 30)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 20
normal! 020|
wincmd w
exe '1resize ' . ((&lines * 60 + 32) / 65)
exe 'vert 1resize ' . ((&columns * 58 + 120) / 240)
exe '2resize ' . ((&lines * 29 + 32) / 65)
exe 'vert 2resize ' . ((&columns * 59 + 120) / 240)
exe '3resize ' . ((&lines * 30 + 32) / 65)
exe 'vert 3resize ' . ((&columns * 59 + 120) / 240)
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
