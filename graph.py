import matplotlib.pyplot as plt
import numpy as np


# # # The figure() function helps in creating a
# # # new figure that can hold a new chart in it.
# # plt.figure()
# # x1 = [0, 1, 2, 3, 4, 5, 6, 7, 9, 10]
# # y1 = [3, 5, 7, 9, 3, 5, 7, 9, 3, 5]
# # y2 = [
# #     1.45985,
# #     1.45985,
# #     1.45985,
# #     3.64963,
# #     5.83942,
# #     0.729927,
# #     6.56934,
# #     32.1168,
# #     18.2482,
# #     0.729927]
# # plt.plot(x1, y2)

# # # Show another chart with '-' dotted line
# # plt.show()
# import matplotlib.pyplot as plt
# import numpy as np
import percentages

# labels = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

# men_means = [20, 34, 30, 35, 27, 20, 34, 30, 35, 27, 56]
# women_means = [25, 32, 34, 20, 25, 20, 34, 30, 35, 27, 75]

# x = np.arange(len(labels))  # the label locations
# width = 0.35  # the width of the bars

# fig, ax = plt.subplots()
# rects1 = ax.bar(x - width/2, percentages.EE2K18sem3, width, label='3sem2K18')
# rects2 = ax.bar(x + width/2, percentages.EE2K18sem6, width, label='3sem2K19')


# # Add some text for labels, title and custom x-axis tick labels, etc.
# ax.set_ylabel('Scores')
# ax.set_title('Scores by 3sem  & sem')
# ax.set_xticks(x)
# ax.set_xticklabels(labels)
# ax.legend()

# ax.bar_label(rects1, padding=3)
# ax.bar_label(rects2, padding=3)



# importing package
import matplotlib.pyplot as plt
  
# create data
x = percentages.CO2K18sem5
y = percentages.CO2K18sem3
  
# plot lines
plt.plot(x, y, label = "line 1")
plt.plot(y, x, label = "line 2")
plt.legend()
plt.show()