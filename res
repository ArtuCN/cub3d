==1302212== Memcheck, a memory error detector
==1302212== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==1302212== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==1302212== Command: ./cub3d maps/map1.cub
==1302212== 
==1302212== Invalid read of size 4
==1302212==    at 0x116CB2: is_same (raycasting3.c:46)
==1302212==    by 0x115B76: init_ray (dda.c:103)
==1302212==    by 0x116197: start_dda (dda.c:166)
==1302212==    by 0x10F9E6: init_cube (init_win.c:78)
==1302212==    by 0x10F674: main (main.c:26)
==1302212==  Address 0x4d84b80 is 0 bytes after a block of size 32 free'd
==1302212==    at 0x483CA3F: free (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
==1302212==    by 0x48A3304: _XReply (in /usr/lib/x86_64-linux-gnu/libX11.so.6.3.0)
==1302212==    by 0x489E930: XSync (in /usr/lib/x86_64-linux-gnu/libX11.so.6.3.0)
==1302212==    by 0x117AD9: mlx_int_new_xshm_image (in /nfs/homes/aconti/cub3d_git/cub3d)
==1302212==    by 0x117D02: mlx_new_image (in /nfs/homes/aconti/cub3d_git/cub3d)
==1302212==    by 0x10F94F: init_cube (init_win.c:70)
==1302212==    by 0x10F674: main (main.c:26)
==1302212==  Block was alloc'd at
==1302212==    at 0x483B7F3: malloc (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
==1302212==    by 0x4D050C5: ??? (in /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0)
==1302212==    by 0x4D02E9E: ??? (in /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0)
==1302212==    by 0x4D0461E: ??? (in /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0)
==1302212==    by 0x4D04795: xcb_wait_for_reply64 (in /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0)
==1302212==    by 0x48A3027: _XReply (in /usr/lib/x86_64-linux-gnu/libX11.so.6.3.0)
==1302212==    by 0x489E930: XSync (in /usr/lib/x86_64-linux-gnu/libX11.so.6.3.0)
==1302212==    by 0x117AD9: mlx_int_new_xshm_image (in /nfs/homes/aconti/cub3d_git/cub3d)
==1302212==    by 0x117D02: mlx_new_image (in /nfs/homes/aconti/cub3d_git/cub3d)
==1302212==    by 0x10F94F: init_cube (init_win.c:70)
==1302212==    by 0x10F674: main (main.c:26)
==1302212== 
==1302212== Invalid read of size 2
==1302212==    at 0x116CB2: is_same (raycasting3.c:46)
==1302212==    by 0x115B76: init_ray (dda.c:103)
==1302212==    by 0x116197: start_dda (dda.c:166)
==1302212==    by 0x10F9E6: init_cube (init_win.c:78)
==1302212==    by 0x10F674: main (main.c:26)
==1302212==  Address 0x4d84b88 is 8 bytes after a block of size 32 free'd
==1302212==    at 0x483CA3F: free (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
==1302212==    by 0x48A3304: _XReply (in /usr/lib/x86_64-linux-gnu/libX11.so.6.3.0)
==1302212==    by 0x489E930: XSync (in /usr/lib/x86_64-linux-gnu/libX11.so.6.3.0)
==1302212==    by 0x117AD9: mlx_int_new_xshm_image (in /nfs/homes/aconti/cub3d_git/cub3d)
==1302212==    by 0x117D02: mlx_new_image (in /nfs/homes/aconti/cub3d_git/cub3d)
==1302212==    by 0x10F94F: init_cube (init_win.c:70)
==1302212==    by 0x10F674: main (main.c:26)
==1302212==  Block was alloc'd at
==1302212==    at 0x483B7F3: malloc (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
==1302212==    by 0x4D050C5: ??? (in /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0)
==1302212==    by 0x4D02E9E: ??? (in /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0)
==1302212==    by 0x4D0461E: ??? (in /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0)
==1302212==    by 0x4D04795: xcb_wait_for_reply64 (in /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0)
==1302212==    by 0x48A3027: _XReply (in /usr/lib/x86_64-linux-gnu/libX11.so.6.3.0)
==1302212==    by 0x489E930: XSync (in /usr/lib/x86_64-linux-gnu/libX11.so.6.3.0)
==1302212==    by 0x117AD9: mlx_int_new_xshm_image (in /nfs/homes/aconti/cub3d_git/cub3d)
==1302212==    by 0x117D02: mlx_new_image (in /nfs/homes/aconti/cub3d_git/cub3d)
==1302212==    by 0x10F94F: init_cube (init_win.c:70)
==1302212==    by 0x10F674: main (main.c:26)
==1302212== 
==1302212== Invalid read of size 4
==1302212==    at 0x116CF6: is_same (raycasting3.c:47)
==1302212==    by 0x115B76: init_ray (dda.c:103)
==1302212==    by 0x116197: start_dda (dda.c:166)
==1302212==    by 0x10F9E6: init_cube (init_win.c:78)
==1302212==    by 0x10F674: main (main.c:26)
==1302212==  Address 0x4d84b70 is 16 bytes inside a block of size 32 free'd
==1302212==    at 0x483CA3F: free (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
==1302212==    by 0x48A3304: _XReply (in /usr/lib/x86_64-linux-gnu/libX11.so.6.3.0)
==1302212==    by 0x489E930: XSync (in /usr/lib/x86_64-linux-gnu/libX11.so.6.3.0)
==1302212==    by 0x117AD9: mlx_int_new_xshm_image (in /nfs/homes/aconti/cub3d_git/cub3d)
==1302212==    by 0x117D02: mlx_new_image (in /nfs/homes/aconti/cub3d_git/cub3d)
==1302212==    by 0x10F94F: init_cube (init_win.c:70)
==1302212==    by 0x10F674: main (main.c:26)
==1302212==  Block was alloc'd at
==1302212==    at 0x483B7F3: malloc (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
==1302212==    by 0x4D050C5: ??? (in /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0)
==1302212==    by 0x4D02E9E: ??? (in /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0)
==1302212==    by 0x4D0461E: ??? (in /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0)
==1302212==    by 0x4D04795: xcb_wait_for_reply64 (in /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0)
==1302212==    by 0x48A3027: _XReply (in /usr/lib/x86_64-linux-gnu/libX11.so.6.3.0)
==1302212==    by 0x489E930: XSync (in /usr/lib/x86_64-linux-gnu/libX11.so.6.3.0)
==1302212==    by 0x117AD9: mlx_int_new_xshm_image (in /nfs/homes/aconti/cub3d_git/cub3d)
==1302212==    by 0x117D02: mlx_new_image (in /nfs/homes/aconti/cub3d_git/cub3d)
==1302212==    by 0x10F94F: init_cube (init_win.c:70)
==1302212==    by 0x10F674: main (main.c:26)
==1302212== 
==1302212== Invalid read of size 2
==1302212==    at 0x116CF6: is_same (raycasting3.c:47)
==1302212==    by 0x115B76: init_ray (dda.c:103)
==1302212==    by 0x116197: start_dda (dda.c:166)
==1302212==    by 0x10F9E6: init_cube (init_win.c:78)
==1302212==    by 0x10F674: main (main.c:26)
==1302212==  Address 0x4d84b78 is 24 bytes inside a block of size 32 free'd
==1302212==    at 0x483CA3F: free (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
==1302212==    by 0x48A3304: _XReply (in /usr/lib/x86_64-linux-gnu/libX11.so.6.3.0)
==1302212==    by 0x489E930: XSync (in /usr/lib/x86_64-linux-gnu/libX11.so.6.3.0)
==1302212==    by 0x117AD9: mlx_int_new_xshm_image (in /nfs/homes/aconti/cub3d_git/cub3d)
==1302212==    by 0x117D02: mlx_new_image (in /nfs/homes/aconti/cub3d_git/cub3d)
==1302212==    by 0x10F94F: init_cube (init_win.c:70)
==1302212==    by 0x10F674: main (main.c:26)
==1302212==  Block was alloc'd at
==1302212==    at 0x483B7F3: malloc (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
==1302212==    by 0x4D050C5: ??? (in /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0)
==1302212==    by 0x4D02E9E: ??? (in /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0)
==1302212==    by 0x4D0461E: ??? (in /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0)
==1302212==    by 0x4D04795: xcb_wait_for_reply64 (in /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0)
==1302212==    by 0x48A3027: _XReply (in /usr/lib/x86_64-linux-gnu/libX11.so.6.3.0)
==1302212==    by 0x489E930: XSync (in /usr/lib/x86_64-linux-gnu/libX11.so.6.3.0)
==1302212==    by 0x117AD9: mlx_int_new_xshm_image (in /nfs/homes/aconti/cub3d_git/cub3d)
==1302212==    by 0x117D02: mlx_new_image (in /nfs/homes/aconti/cub3d_git/cub3d)
==1302212==    by 0x10F94F: init_cube (init_win.c:70)
==1302212==    by 0x10F674: main (main.c:26)
==1302212== 
==1302212== Invalid read of size 4
==1302212==    at 0x1164D9: get_color (draw.c:64)
==1302212==    by 0x116811: adding_pix_to_img (draw.c:126)
==1302212==    by 0x1161F8: start_dda (dda.c:172)
==1302212==    by 0x10F9E6: init_cube (init_win.c:78)
==1302212==    by 0x10F674: main (main.c:26)
==1302212==  Address 0x1ffe000135 is not stack'd, malloc'd or (recently) free'd
==1302212== 
==1302212== 
==1302212== Process terminating with default action of signal 11 (SIGSEGV)
==1302212==  Access not within mapped region at address 0x1FFE000135
==1302212==    at 0x1164D9: get_color (draw.c:64)
==1302212==    by 0x116811: adding_pix_to_img (draw.c:126)
==1302212==    by 0x1161F8: start_dda (dda.c:172)
==1302212==    by 0x10F9E6: init_cube (init_win.c:78)
==1302212==    by 0x10F674: main (main.c:26)
==1302212==  If you believe this happened as a result of a stack
==1302212==  overflow in your program's main thread (unlikely but
==1302212==  possible), you can try to increase the size of the
==1302212==  main thread stack using the --main-stacksize= flag.
==1302212==  The main thread stack size used in this run was 8388608.
==1302212== 
==1302212== HEAP SUMMARY:
==1302212==     in use at exit: 348,611 bytes in 179 blocks
==1302212==   total heap usage: 1,595 allocs, 1,416 frees, 675,754 bytes allocated
==1302212== 
==1302212== LEAK SUMMARY:
==1302212==    definitely lost: 0 bytes in 0 blocks
==1302212==    indirectly lost: 0 bytes in 0 blocks
==1302212==      possibly lost: 0 bytes in 0 blocks
==1302212==    still reachable: 348,611 bytes in 179 blocks
==1302212==         suppressed: 0 bytes in 0 blocks
==1302212== Reachable blocks (those to which a pointer was found) are not shown.
==1302212== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==1302212== 
==1302212== For lists of detected and suppressed errors, rerun with: -s
==1302212== ERROR SUMMARY: 7 errors from 5 contexts (suppressed: 1 from 1)
