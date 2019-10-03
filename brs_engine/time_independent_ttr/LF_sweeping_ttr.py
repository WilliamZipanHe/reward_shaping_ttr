import numpy as np
import os
import sys

import copy


# test dynamic nested loop


# max = [10, 9, 5, 6]
# max = [1, 1, 1, 1, 10, 9, 5, 6]


dims = 3
pd_dims = [2]
# N = [10, 10, 10, 10]
N = [53, 41, 100]
# N = [3,3,3]
# N = [100, 41, 53]
# index 0 and 2 are periodic
def NestedLoop(dims, N):

    init_slots  = np.array([0] * dims + [1] * dims)

    for i in range(dims):
        if i in pd_dims:
            init_slots[i] = N[i] - 1 if init_slots[i+dims] < 0 else 0
        else:
            init_slots[i] = N[i] - 2 if init_slots[i+dims] < 0 else 1

    index = 0

    derivs = [None] * dims
    count = 0

    cur_slots = copy.deepcopy(init_slots)
    while True:
        # check init_slots, step_slots and end_slots at every single loop inner

        old_init_slots = init_slots

        init_slots = np.array([0] * dims + [1] * dims)
        # step_slots = np.array([cur_slots[dims], cur_slots[dims+1], cur_slots[dims+2], cur_slots[dims+3], -2, -2, -2, -2])
        step_slots = np.array([cur_slots[dims+k] for k in range(dims)] + [-2] * dims)
        end_slots  = np.array([0] * dims + [-1] * dims)

        for i in range(dims):
            if i in pd_dims:
                end_slots[i] = 0 if cur_slots[i+dims] < 0 else N[i]-1
                init_slots[i] = N[i] - 1 if cur_slots[i+dims] < 0 else 0
            else:
                end_slots[i] = 1 if cur_slots[i+dims] < 0 else N[i]-2
                init_slots[i] = N[i] - 2 if cur_slots[i+dims] < 0 else 1

        for j in range(dims*2):
            if old_init_slots[j] != init_slots[j]:
                cur_slots[j] = init_slots[j]

        # main for-loop for each process
        # pass
        # for dim in range(dims):
        #     if dim in pd_dims:
        #         if slots[dim] == 0:
        #             derivs[dim] = 10
        #         elif slots[dim] == max[dim]:
        #             derivs[dim] = 9
        #         else:
        #             derivs[dim] = 8
        #     else:
        #         derivs[dim] = 8
        count += 1
        # slots[0] += 1
        cur_slots[0] = cur_slots[0] + step_slots[0]

        while cur_slots[index] == end_slots[index] + step_slots[index]:
            if index == dims * 2 - 1:
                print("cur_slots:", cur_slots)
                print("init_slots:", init_slots)
                print("end_slots:", end_slots)
                print("step slots:", step_slots)
                print("max number of loop:", count)
                return
            cur_slots[index] = init_slots[index]
            index += 1
            cur_slots[index] += step_slots[index]

        index = 0

if __name__ == "__main__":
    NestedLoop(dims, N)

