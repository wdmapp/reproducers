hip_unravel_reproducer: src/hip_unravel_reproducer.cxx
	hipcc -g -O2 --amdgpu-target=gfx1030,gfx90a:xnack+ -std=gnu++14 -o $@ $<
