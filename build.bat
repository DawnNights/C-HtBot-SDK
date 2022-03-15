gcc -c -DBUILD_DLL main.c -m32 -fexec-charset=GBK
gcc -shared -o C-Plugin.ht.dll main.o -Wl,--kill-at,--out-implib,libmydll.a -m32
del main.o libmydll.a