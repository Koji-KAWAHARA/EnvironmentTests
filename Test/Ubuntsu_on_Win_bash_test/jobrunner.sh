#!/bin/sh
#list of coupling consts
C_list=("0.01" "0.02" "0.03" "0.04" "0.05" "0.06" "0.07" "0.08" "0.09" "0.10")

#list of position of FG_DW
#FGDW_position_list=("0") -fixed position at 0
FPDW_position_list=("0.333")
GPDW_position_list=("0.666")

#parent directory name, incorporate date for easy revise later on
parent_dir="./RUNS_20220726"

for C in ${C_list[@]};do
  for FPDW_position in ${FGDW_position_list[@]};do
    for GPDW_position in ${FGDW_position_list[@]};do
      case_dir = ${parent_dir}/C_${C}_FP_${FPDW_position}_GP_${GPDW_position}

      mkdir -p ${parent_dir}                                              
      mkdir -p ${case_dir}
      mkdir -p ${case_dir}/detail
      mkdir -p ${case_dir}/graph
      # -p option means "do nothing if target exists"
    done
  done
done

pids=()  # process id array
for C in ${C_list[@]};do
  for FPDW_position in ${FGDW_position_list[@]};do
    for GPDW_position in ${FGDW_position_list[@]};do
      case_dir = ${parent_dir}/C_${C}_FP_${FPDW_position}_GP_${GPDW_position}
      shname=${case_dir}/job.sh                       # make new sh file according to parameters
      : > $shname                                     # clear existing file
      cat single_job_template.sh > $shname            # copy from template
      echo "./a.out  --folder ${fname} --mode ${mode} --C ${C} --H ${H} --Fdepth 100 --Gdepth 100 --Nx 1000 --Ny 3 --Nz 3 --maxloop 500001" >> $shname
      sh ./$shname &                                   # the last "&" means "exec. as background process", critical for parallelization
      pids[$!]=$! # get process id of latest subprocess
    done
  done
done
wait ${pids[@]}
echo "Done all process."
