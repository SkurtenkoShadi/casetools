AUTOMAKE_OPTIONS = foreign
SUBDIRS = source
EXTRA_DIST = doxs external

DIR_DOX = doxs

.DEFAULT: 
	@make default
	
.SILENT: wc

doc:
	@cd ${DIR_DOX} && doxygen Doxyfile

doc_delete:
	@cd ${DIR_DOX} && mv image Doxyfile README.md ..
	-@rm -rf ${DIR_DOX}
	@mkdir ${DIR_DOX}
	@mv image Doxyfile README.md ${DIR_DOX}

wc: ${wildcard source/*.cpp} ${wildcard source/*.h}
	echo "newline word byte name"
	wc $^

default:
	@echo "Доступные цели makefile:"
	@echo " doc - создание документации проекта;"
	@echo " wc - вывод статичтической информации по *.cpp файлам;"
	@echo " doc_delete - удалить документацию."
	@echo " distclean - "
	@echo " clean - ."
	@echo " dist - ."
	@echo " all - ."