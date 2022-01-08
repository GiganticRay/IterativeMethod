import re
import numpy as np
import matplotlib.pyplot as plt
import os

def Read_CG_Out(fileDir, fileName, fileExt):
	filePath = os.path.join(fileDir, fileName) + fileExt
	outputDir = os.path.join(fileDir, fileName)
	if(os.path.exists(outputDir) is not True):
		os.mkdir(outputDir)
	
	outputFilePath = os.path.join(outputDir, fileName+".png")

	with open(filePath, "r") as f:
		f.readline()

		f_val 	= []
		res 	= []
		while(f.readline()):
			line_content = f.readline()
			line_content = re.findall(r"-?\d+\.?\d*", line_content)
			if len(line_content) == 2:
				f_val.append(float(line_content[0]))
				res.append(float(line_content[1]))

		f_val = np.array(f_val)
		res = np.array(res)
		x = range(len(f_val))

		plt.subplot(1, 2, 1)	# 1 行 2 列，采用第 1 个子图
		plt.plot(x, f_val, 'r--', label='f', markevery = 100)
		plt.title(fileName)
		plt.xlabel('iteration')
		plt.ylabel('f_val')
		plt.legend()

		plt.subplot(1, 2, 2)
		plt.plot(x, res, 'r--', label='res_ratio', markevery = 100)
		plt.title(fileName)
		plt.xlabel('iteration')
		plt.ylabel('res_val_ratio')
		plt.legend()

		plt.savefig(outputFilePath)


if __name__ == "__main__":
	fileDir 	= "/public/home/LeiChao/Document/IterativeMethod/OUTPUT"
	fileName	= "CG_1000_generated_output"
	fileExt		= ".txt"

	# CG
	Read_CG_Out(fileDir, fileName, fileExt)
