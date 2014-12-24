" Activate the Pathogen plugin
execute pathogen#infect()

" Mark all indentations 4 wide and spaces
set tabstop=4
set shiftwidth=4
set expandtab

" Make backspace work how we'd like it to
set backspace=2

" Turn on syntax highlighting
syntax on

" Turn on line numbers
set number

" Add a line length guard
set colorcolumn=100
highlight ColorColumn ctermbg=darkgray

" Enable doxygen highlighting in addition to cpp highlighting
augroup project
    autocmd!
    autocmd BufRead,BufNewFile *.h,*.cpp set filetype=cpp.doxygen
    autocmd BufRead,BufNewFile *SConstruct,*SConscript set filetype=python.doxygen
    autocmd CursorMovedI * if pumvisible() == 0|pclose|endif
    autocmd InsertLeave * if pumvisible() == 0|pclose|endif
augroup END

" Set up the inclusion paths
let &path.="include,src"

" Build with SCons
set makeprg=scons\ -j4
nnoremap <F4> :make!<cr>
