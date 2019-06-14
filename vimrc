colorscheme elflord
set number
set modeline
set expandtab
set cursorline
set ls=2
set incsearch
set formatoptions+=w
set tw=80
set colorcolumn=80
map <F2> : set number!<CR>
map <F3> : TlistToggle<CR>
map <F4> : set nowrap!<CR>
map <F5> : set hlsearch!<CR>
map <F6> : set cursorline!<CR>
map <F7> : set expandtab!<CR>
map <F8> : NERDTreeToggle<CR>
map <F9> : set relativenumber!<CR>

"<Instantly better Vim- Conway>"
set spelllang=en_us
map <F10> : set spell!<CR>
function! HLNext (blinktime)
          highlight RedOnWhite ctermfg=red ctermbg=white
          let [bufnum, lnum, col, off] = getpos('.')
          let matchlen = strlen(matchstr(strpart(getline('.'),col-1),@/))
          let target_pat = '\c\%#'.@/
          let ring = matchadd('RedOnWhite', target_pat, 101)
          redraw
          exec 'sleep ' . float2nr(a:blinktime * 2000) . 'm'
          call matchdelete(ring)
          redraw
endfunction
nnoremap <silent> n   n:call HLNext(0.4)<cr>
nnoremap <silent> N   N:call HLNext(0.4)<cr>
"</Instantly better Vim- Conway>"

fun! ShowFuncName()
  let lnum = line(".")
  let col = col(".")
  echohl ModeMsg
  echo getline(search("^[^ \t#/]\\{2}.*[^:]\s*$", 'bW'))
  echohl None
  call search("\\%" . lnum . "l" . "\\%" . col . "c")
endfun
map f :call ShowFuncName() <CR>
