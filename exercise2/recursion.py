#!/usr/bin/env python3
#-*- conding: utf-8 -*-
import sys, os, tarfile, time

# 用于记录文件个数和文件中数值总和的字典
statistics = dict({'num_of_file': 0, 'positive_value': 0})

# 解压文件，并统计其中每个文件中非负整数的总和
def unpack_gz_file(path):
	if os.path.isfile(path):
		if tarfile.is_tarfile(path):
			archive = tarfile.open(path, 'r:gz')	# 解压文件
			for tarinfo in archive:
				# 将压缩文件中的内容提取出来，放到当前目录下
				archive.extract(tarinfo, os.path.dirname(path))
				# 递归调用自身
				unpack_gz_file(os.path.join(os.path.dirname(path), tarinfo.name))
		else:
			statistics['num_of_file'] += 1
			# 打开文件并读取其中的非负整数
			with open(path) as fo:
				for line in fo:
					try:
						if int(line) > 0:
							statistics['positive_value'] += int(line)
					except ValueError as e:
						pass

def main():
	# 获取压缩文件名
	args = sys.argv
	if len(args) == 1:
		gz_file_path = input('Please input the path of the gz file:')
	elif len(args) == 2:
		gz_file_path = args[1]

	# 将文件名转为绝对路径	
	if (os.path.isabs(gz_file_path) != True):
		gz_file_path = os.path.abspath(gz_file_path)

	print('The input file is :', gz_file_path)
	print('Running the program, please wait for the result...')

	# 统计运行时间
	start = time.time()
	unpack_gz_file(gz_file_path)
	end = time.time()

	# 输出结果
	print('End.\nThe total run time is: ', end-start)
	print('The result is :', statistics)


if __name__=='__main__':
	main()