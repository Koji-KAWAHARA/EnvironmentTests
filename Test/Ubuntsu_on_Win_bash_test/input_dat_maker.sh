#!/bin/bash

#parent directory name, incorporate date for easy revise later on
parent_dir="./RUNS_20220726"

#list of coupling consts
C_list="0.01 0.02"
#C_list=("0.01" "0.02" "0.03" "0.04" "0.05" "0.06" "0.07" "0.08" "0.09" "0.10")

#list of position of DWs. FGDW is fixed at position 0. "1" means 2pi.
FPDW_position_list="0.333"
GPDW_position_list="0.666"

maxloop="100000"
save_interval="1000"
savelist="0 1 10 100"
fg_sourcefile="NON"
fp_sourcefile="NON"
gp_sourcefile="NON"

#model parameters
Nr="500"
Nth="500"
minR="0.10"
maxR="100"
H="0"
E="0"
Kf="8.0"
Kg="1.0"
Kp="0.5"
Afx="-0.4"
Afy="-0.3"
Agx="-0.05"
Agy="-0.02"
Ap="1.0"

dt="0.000001"
max_spin_movemet_per_single_step="0.01"

INI_MODE="TRI_DW_vortex"
#INI_MODE="TRI_DW_planer"
#----
#INI_MODE="SUPER_FLAT"
#INI_MODE="TRI_DW_orig"
#INI_MODE="SINGLE_GD_DW"
#INI_MODE="RANDOM"
OP_fluctuation="0.00001"


#-----------------------------------------------------------------
#create necessary directories
mkdir -p ${parent_dir}
for C in ${C_list[@]};do
  for FPDW_position in ${FPDW_position_list[@]};do
    for GPDW_position in ${GPDW_position_list[@]};do
      #directory for each simulation run.
      case_dir=${parent_dir}/C_${C}_FP_${FPDW_position}_GP_${GPDW_position}                                          
      mkdir -p ${case_dir}
      mkdir -p ${case_dir}/detail
      mkdir -p ${case_dir}/graph
      # -p option means "do nothing if target exists"
    done
  done
done


for C in ${C_list[@]};do
  for FPDW_position in ${FPDW_position_list[@]};do
    for GPDW_position in ${GPDW_position_list[@]};do
      case_dir=${parent_dir}/C_${C}_FP_${FPDW_position}_GP_${GPDW_position}
      model_parm_dat=${case_dir}/model_parm.dat
      setting_dat=${case_dir}/setting.dat

      #write setting.dat
      #initialize
      : > $setting_dat
      #write
      echo -e "#test simulation setting"          >>$setting_dat
      echo -e "simumode = CG"                     >>$setting_dat
      echo -e "Position_FPwall = $FPDW_position"  >>$setting_dat
      echo -e "Position_GPwall = $GPDW_position"  >>$setting_dat
      echo -e "maxloop=$maxloop"                  >>$setting_dat
      echo -e ""                                  >>$setting_dat
      echo -e "IO_FOLDER=$case_dir"               >>$setting_dat
      echo -e "INI_CONFIG=$case_dir/Bulk1.txt"    >>$setting_dat
      echo -e "logfile=$case_dir/log.txt"         >>$setting_dat
      echo -e "save_interval=$save_interval"      >>$setting_dat
      echo -e "fg_sourcefile = $fg_sourcefile"    >>$setting_dat
      echo -e "fp_sourcefile = $fp_sourcefile"    >>$setting_dat
      echo -e "gp_sourcefile = $gp_sourcefile"    >>$setting_dat


      #write model_parm.dat
      #initialize : clear existing file
      : > $model_parm_dat
      #write
      echo -e "#model parameters"                >>$model_parm_dat
      echo -e "Nr=${Nr}\nNth=${Nth}"           >>$model_parm_dat
      echo -e "minR=${minR}\nmaxR=${maxR}"     >>$model_parm_dat
      echo -e "H=${H}\nE=${E}"                 >>$model_parm_dat
      echo -e "Kf=${Kf}\nKg=${Kg}\nKp=${Kp}"     >>$model_parm_dat
      echo -e "Afx=${Afx}\nAfy=${Afy}"         >>$model_parm_dat
      echo -e "Agx=${Agx}\nAgy=${Agy}"         >>$model_parm_dat
      echo -e "Ap=${Ap}"                       >>$model_parm_dat
      echo -e "C=${C}"                         >>$model_parm_dat
      echo -e "dt=${dt}"                       >>$model_parm_dat
      echo -e ""                               >>$model_parm_dat
      echo -e "max_spin_movemet_per_single_step = ${max_spin_movemet_per_single_step}\n#<-in unit of M_PI">>$model_parm_dat
      echo -e "INI_MODE=${INI_MODE}"             >>$model_parm_dat
      echo -e "OP_fluctuation=${OP_fluctuation}" >>$model_parm_dat

      #cat single_job_template.sh > $shname            # copy from template
      #echo "./a.out  --folder ${fname} --mode ${mode} --C ${C} --H ${H} --Fdepth 100 --Gdepth 100 --Nx 1000 --Ny 3 --Nz 3 --maxloop 500001" >> $shname
      #sh ./$shname &                                   # the last "&" means "exec. as background process", critical for parallelization
      #pids[$!]=$! # get process id of latest subprocess
    done
  done
done
echo "Done all process."
