import seaborn as sns
import pandas as pd
import numpy as np 
import matplotlib.pyplot as plt 
import pickle 

import argparse

# params need to be parsed: env[quad, car]; stage:[train,eval]; measurements:[time,reward,success_rate]

# parser = argparse.ArgumentParser()
# parser.add_argument("--env", help="which environment to use.", type=str, default='quad')
# parser.add_argument("--stage", help="which stage you want plot for.", type=str, default='train')
# parser.add_argument("--measures", help="which type of algorithm to use.", type=str, default='reward')
# args = parser.parse_args()

# Quad_train_ttr_paths = \
# ['/home/xlv/Desktop/IROS2019/runs_reborn/PlanarQuadEnv-v0_ttr_28-Feb-2019_12-44-01',
# '/home/xlv/Desktop/IROS2019/runs_paper/PlanarQuadEnv-v0_ttr_24-Feb-2019_20-33-35']
# Quad_train_sparse_paths = \
# ['/home/xlv/Desktop/IROS2019/runs_paper/PlanarQuadEnv-v0_hand_craft_25-Feb-2019_03-22-52',
# '/home/xlv/Desktop/IROS2019/runs_paper/PlanarQuadEnv-v0_hand_craft_25-Feb-2019_05-03-22']
# Quad_train_distance_paths = \
# ['/home/xlv/Desktop/IROS2019/runs_reborn/PlanarQuadEnv-v0_distance_28-Feb-2019_18-43-57',
# '/home/xlv/Desktop/IROS2019/runs_reborn/PlanarQuadEnv-v0_distance_28-Feb-2019_20-17-31']
# # Quad_eval_ttr_paths = \
# # ['/home/xlv/Desktop/IROS2019/runs_paper/PlanarQuadEnv-v0_ttr_24-Feb-2019_20-33-35_iter_10_eval',
# # '/home/xlv/Desktop/IROS2019/runs_paper/PlanarQuadEnv-v0_ttr_24-Feb-2019_22-18-18_iter_6_eval']
# Quad_eval_ttr_paths = \
# ['/home/xlv/Desktop/IROS2019/runs_reborn/PlanarQuadEnv-v0_ttr_28-Feb-2019_12-44-01_iter_8_eval_record',
# '/home/xlv/Desktop/IROS2019/runs_reborn/PlanarQuadEnv-v0_ttr_28-Feb-2019_12-44-01_iter_9_eval_record']
# Quad_eval_sparse_paths = \
# ['/home/xlv/Desktop/IROS2019/runs_paper/PlanarQuadEnv-v0_hand_craft_25-Feb-2019_03-22-52_iter_10_eval',
# '/home/xlv/Desktop/IROS2019/runs_paper/PlanarQuadEnv-v0_hand_craft_25-Feb-2019_05-03-22_iter_10_eval']
# # Quad_eval_distance_paths = \
# # ['/home/xlv/Desktop/IROS2019/runs_paper/PlanarQuadEnv-v0_distance_25-Feb-2019_00-02-04_iter_10_eval',
# # '/home/xlv/Desktop/IROS2019/runs_paper/PlanarQuadEnv-v0_distance_25-Feb-2019_01-41-56_iter_10_eval']
# Quad_eval_distance_paths = \
# ['/home/xlv/Desktop/IROS2019/runs_reborn/PlanarQuadEnv-v0_distance_28-Feb-2019_18-43-57_iter_10_eval_record',
# '/home/xlv/Desktop/IROS2019/runs_reborn/PlanarQuadEnv-v0_distance_28-Feb-2019_20-17-31_iter_10_eval_record']

# Car_train_ttr_paths = \
# ['/home/xlv/Desktop/IROS2019/runs_paper/DubinsCarEnv-v0_ttr_23-Feb-2019_10-33-57',
# '/home/xlv/Desktop/IROS2019/runs_paper/DubinsCarEnv-v0_ttr_23-Feb-2019_13-31-37',
# '/home/xlv/Desktop/IROS2019/runs_paper/DubinsCarEnv-v0_ttr_23-Feb-2019_16-25-18']
# Car_train_sparse_paths = \
# ['/home/xlv/Desktop/IROS2019/runs_paper/DubinsCarEnv-v0_hand_craft_23-Feb-2019_23-01-51',
# '/home/xlv/Desktop/IROS2019/runs_paper/DubinsCarEnv-v0_hand_craft_23-Feb-2019_23-57-09']
# Car_train_distance_paths = \
# ['/home/xlv/Desktop/IROS2019/runs_paper/DubinsCarEnv-v0_distance_23-Feb-2019_18-27-53',
# '/home/xlv/Desktop/IROS2019/runs_paper/DubinsCarEnv-v0_distance_23-Feb-2019_19-24-36',
# '/home/xlv/Desktop/IROS2019/runs_paper/DubinsCarEnv-v0_distance_23-Feb-2019_20-20-26']
# Car_eval_ttr_paths = \
# ['/home/xlv/Desktop/IROS2019/runs_paper/DubinsCarEnv-v0_ttr_23-Feb-2019_10-33-57_iter_10_eval',
# '/home/xlv/Desktop/IROS2019/runs_paper/DubinsCarEnv-v0_ttr_23-Feb-2019_13-31-37_iter_10_eval',
# '/home/xlv/Desktop/IROS2019/runs_paper/DubinsCarEnv-v0_ttr_23-Feb-2019_16-25-18_iter_10_eval']
# Car_eval_sparse_paths = \
# ['/home/xlv/Desktop/IROS2019/runs_paper/DubinsCarEnv-v0_hand_craft_23-Feb-2019_23-01-51_iter_10_eval',
# '/home/xlv/Desktop/IROS2019/runs_paper/DubinsCarEnv-v0_hand_craft_23-Feb-2019_23-57-09_iter_10_eval']
# Car_eval_distance_paths = \
# ['/home/xlv/Desktop/IROS2019/runs_paper/DubinsCarEnv-v0_distance_23-Feb-2019_18-27-53_iter_10_eval',
# '/home/xlv/Desktop/IROS2019/runs_paper/DubinsCarEnv-v0_distance_23-Feb-2019_19-24-36_iter_10_eval',
# '/home/xlv/Desktop/IROS2019/runs_paper/DubinsCarEnv-v0_distance_23-Feb-2019_20-20-26_iter_10_eval']

# # measurement 1: cumulative reward. need standarization
# # measurement 2: success percent.
# # measurement 3: wall clock time.
# if args.env == 'quad':
#     if args.stage == 'train':
#         ttr_paths = Quad_train_ttr_paths
#         sparse_paths = Quad_train_sparse_paths
#         distance_paths = Quad_train_distance_paths
#     elif args.stage == 'eval':
#         ttr_paths = Quad_eval_ttr_paths
#         sparse_paths = Quad_eval_sparse_paths
#         distance_paths = Quad_eval_distance_paths
# elif args.env == 'car':
#     if args.stage == 'train':
#         ttr_paths = Car_train_ttr_paths
#         sparse_paths = Car_train_sparse_paths
#         distance_paths = Car_train_distance_paths
#     elif args.stage == 'eval':
#         ttr_paths = Car_eval_ttr_paths
#         sparse_paths = Car_eval_sparse_paths
#         distance_paths = Car_eval_distance_paths
# else:
#     raise ValueError("env is invalid!")

# # time is not approperiate. don't use it now.
# if args.measures == 'time':
#     suffix = '/result/wall_clock_time_iter_10.pickle'
#     x_range = 10
# elif args.measures == 'reward':
#     suffix = '/result/ppo_reward_iter_10.pickle'
#     x_range = 300
#     if args.stage == 'eval':
#         x_label = 'evaluation episodes'
#     else:
#         x_label = 'PPO iterations'
#     y_label = 'average reward'
# elif args.measures == 'success_rate':
#     suffix = '/result/success_percent_iter_10.pickle'
#     x_range = 10
#     x_label = 'Algorithm iterations'
#     y_label = 'success rate'

# x = []
# y = []
# for idx in range(len(ttr_paths)):
#     if args.measures == 'time':
#         tmp_x = pickle.load(open(ttr_paths[idx]+suffix,'rb'))
#         tmp_x[:] = [i - tmp_x[0] for i in tmp_x]
#         x += tmp_x
#         tmp_y = pickle.load(open(ttr_paths[idx]+'/result/ppo_reward_iter_10.pickle','rb')) 
#         y += tmp_y[0:-1:30]
#     else:
#         x += [i for i in range(x_range)]
#         y += pickle.load(open(ttr_paths[idx]+suffix,'rb')) 
# np_x = np.array(x)
# np_y = np.array(y)
# df = pd.DataFrame({'col1':np_x, 'col2':np_y}) 
# sns.lineplot(x="col1", y="col2", ci="sd", estimator='mean', data=df, label='TTR') 
# x = []
# y = []
# for idx in range(len(sparse_paths)):
#     if args.measures == 'time':
#         tmp_x = pickle.load(open(sparse_paths[idx]+suffix,'rb'))
#         tmp_x[:] = [i - tmp_x[0] for i in tmp_x]
#         x += tmp_x
#         tmp_y = pickle.load(open(sparse_paths[idx]+'/result/ppo_reward_iter_10.pickle','rb')) 
#         y += tmp_y[0:-1:30]
#     else:
#         x += [i for i in range(x_range)]
#         y += pickle.load(open(sparse_paths[idx]+suffix,'rb')) 
# np_x = np.array(x)
# np_y = np.array(y)
# df = pd.DataFrame({'col1':np_x, 'col2':np_y}) 
# sns.lineplot(x="col1", y="col2", ci="sd", estimator='mean', data=df, label='sparse')
# x = []
# y = []
# for idx in range(len(distance_paths)):
#     if args.measures == 'time':
#         tmp_x = pickle.load(open(distance_paths[idx]+suffix,'rb'))
#         tmp_x[:] = [i - tmp_x[0] for i in tmp_x]
#         x += tmp_x
#         tmp_y = pickle.load(open(distance_paths[idx]+'/result/ppo_reward_iter_10.pickle','rb')) 
#         y += tmp_y[0:-1:30]
#     else:
#         x += [i for i in range(x_range)]
#         y += pickle.load(open(distance_paths[idx]+suffix,'rb')) 
# np_x = np.array(x)
# np_y = np.array(y)
# df = pd.DataFrame({'col1':np_x, 'col2':np_y}) 
# sns.lineplot(x="col1", y="col2", ci="sd", estimator='mean', data=df, label='distance')

# plt.legend(loc='upper left',frameon = True) 
# plt.xlabel(x_label)
# plt.ylabel(y_label)
# plt.show()

x_range=300
path='' # you define
x = []
y = []
# x is range: 0~299
x += [i for i in range(x_range)]
# y is the data along 0~299
y += pickle.load(open(path+'/result/ppo_reward_iter_10.pickle','rb')) 
np_x = np.array(x)
np_y = np.array(y)

# plot mean and variance in form of bar plot.
# ...


# these two lines below could not be used
# df = pd.DataFrame({'col1':np_x, 'col2':np_y}) 
# sns.lineplot(x="col1", y="col2", ci="sd", estimator='mean', data=df, label='TTR') 