#basic usage
#sed 's/(置換前の文字)/(置換後の文字)/g'
# "g" means "replace all"
#"-i" option means "inplace"
#"-z" option lets "\n" code handling 

#this does not rewrite file. only show replaced txt on terminal.
#sed 's/#define ONEDIM_ANNEAL/\/\/#define ONEDIM_ANNEAL)/g' sample.hpp

#this rewrites sourcefile. "-i" option means "inplace"
#sed -i -z 's/\n\/\/#define ONEDIM_ANNEAL/\n#define ONEDIM_ANNEAL/g' sample.hpp
#cat sample.hpp
sed -i -z 's/\n#define ONEDIM_ANNEAL/\n\/\/#define ONEDIM_ANNEAL/g' sample.hpp
cat sample.hpp