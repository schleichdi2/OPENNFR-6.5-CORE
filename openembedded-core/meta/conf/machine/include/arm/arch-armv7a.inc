DEFAULTTUNE ?= "armv7athf"
ARM_INSTRUCTION_SET ?= "thumb"

TUNEVALID[armv7a] = "Enable instructions for ARMv7-a"
TUNECONFLICTS[armv7a] = "armv4 armv5 armv6 armv7"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'armv7a', ' -march=armv7-a', '', d)}"
MACHINEOVERRIDES =. "${@bb.utils.contains('TUNE_FEATURES', 'armv7a', 'armv7a:', '', d)}"

require conf/machine/include/arm/arch-armv6.inc
require conf/machine/include/arm/feature-arm-neon.inc

# Little Endian base configs
AVAILTUNES += "armv7a armv7at armv7a-vfpv3d16 armv7at-vfpv3d16 armv7a-vfpv3 armv7at-vfpv3 armv7a-vfpv4d16 armv7at-vfpv4d16 armv7a-neon armv7at-neon armv7a-neon-vfpv4 armv7at-neon-vfpv4"
ARMPKGARCH_tune-armv7a             ?= "armv7a"
ARMPKGARCH_tune-armv7at            ?= "armv7a"
ARMPKGARCH_tune-armv7a-vfpv3d16    ?= "armv7a"
ARMPKGARCH_tune-armv7at-vfpv3d16   ?= "armv7a"
ARMPKGARCH_tune-armv7a-vfpv3       ?= "armv7a"
ARMPKGARCH_tune-armv7at-vfpv3      ?= "armv7a"
ARMPKGARCH_tune-armv7a-vfpv4d16    ?= "armv7a"
ARMPKGARCH_tune-armv7at-vfpv4d16   ?= "armv7a"
ARMPKGARCH_tune-armv7a-neon        ?= "armv7a"
ARMPKGARCH_tune-armv7at-neon       ?= "armv7a"
ARMPKGARCH_tune-armv7a-neon-vfpv4  ?= "armv7a"
ARMPKGARCH_tune-armv7at-neon-vfpv4 ?= "armv7a"
TUNE_FEATURES_tune-armv7a             = "arm armv7a vfp"
TUNE_FEATURES_tune-armv7at            = "${TUNE_FEATURES_tune-armv7a} thumb"
TUNE_FEATURES_tune-armv7a-vfpv3d16    = "${TUNE_FEATURES_tune-armv7a} vfpv3d16"
TUNE_FEATURES_tune-armv7at-vfpv3d16   = "${TUNE_FEATURES_tune-armv7at} vfpv3d16"
TUNE_FEATURES_tune-armv7a-vfpv3       = "${TUNE_FEATURES_tune-armv7a-vfpv3d16} vfpv3"
TUNE_FEATURES_tune-armv7at-vfpv3      = "${TUNE_FEATURES_tune-armv7at-vfpv3d16} vfpv3"
TUNE_FEATURES_tune-armv7a-vfpv4d16    = "${TUNE_FEATURES_tune-armv7a} vfpv4d16"
TUNE_FEATURES_tune-armv7at-vfpv4d16   = "${TUNE_FEATURES_tune-armv7at} vfpv4d16"
TUNE_FEATURES_tune-armv7a-neon        = "${TUNE_FEATURES_tune-armv7a} neon"
TUNE_FEATURES_tune-armv7at-neon       = "${TUNE_FEATURES_tune-armv7at} neon"
TUNE_FEATURES_tune-armv7a-neon-vfpv4  = "${TUNE_FEATURES_tune-armv7a-neon} vfpv4"
TUNE_FEATURES_tune-armv7at-neon-vfpv4 = "${TUNE_FEATURES_tune-armv7at-neon} vfpv4"
PACKAGE_EXTRA_ARCHS_tune-armv7a             = "${PACKAGE_EXTRA_ARCHS_tune-armv6} armv7a armv7a-vfp"
PACKAGE_EXTRA_ARCHS_tune-armv7at            = "${PACKAGE_EXTRA_ARCHS_tune-armv6t} armv7a armv7a-vfp armv7at2-vfp"
PACKAGE_EXTRA_ARCHS_tune-armv7a-vfpv3d16    = "${PACKAGE_EXTRA_ARCHS_tune-armv7a} armv7a-vfpv3d16"
PACKAGE_EXTRA_ARCHS_tune-armv7at-vfpv3d16   = "${PACKAGE_EXTRA_ARCHS_tune-armv7at} armv7a-vfpv3d16 armv7at2-vfpv3d16"
PACKAGE_EXTRA_ARCHS_tune-armv7a-vfpv3       = "${PACKAGE_EXTRA_ARCHS_tune-armv7a-vfpv3d16} armv7a-vfpv3"
PACKAGE_EXTRA_ARCHS_tune-armv7at-vfpv3      = "${PACKAGE_EXTRA_ARCHS_tune-armv7at-vfpv3d16} armv7a-vfpv3 armv7at2-vfpv3"
PACKAGE_EXTRA_ARCHS_tune-armv7a-vfpv4d16    = "${PACKAGE_EXTRA_ARCHS_tune-armv7a} armv7a-vfpv4d16"
PACKAGE_EXTRA_ARCHS_tune-armv7at-vfpv4d16   = "${PACKAGE_EXTRA_ARCHS_tune-armv7at} armv7a-vfpv4d16 armv7at2-vfpv4d16"
PACKAGE_EXTRA_ARCHS_tune-armv7a-neon        = "${PACKAGE_EXTRA_ARCHS_tune-armv7a} armv7a-neon"
PACKAGE_EXTRA_ARCHS_tune-armv7at-neon       = "${PACKAGE_EXTRA_ARCHS_tune-armv7at} armv7a-neon armv7at2-neon"
PACKAGE_EXTRA_ARCHS_tune-armv7a-neon-vfpv4  = "${PACKAGE_EXTRA_ARCHS_tune-armv7a-neon} armv7a-neon-vfpv4"
PACKAGE_EXTRA_ARCHS_tune-armv7at-neon-vfpv4 = "${PACKAGE_EXTRA_ARCHS_tune-armv7at-neon} armv7a-neon-vfpv4 armv7at2-neon-vfpv4"

# HF Tunes
AVAILTUNES += "armv7ahf armv7athf armv7ahf-vfpv3d16 armv7athf-vfpv3d16 armv7ahf-vfpv3 armv7athf-vfpv3 armv7ahf-vfpv4d16 armv7athf-vfpv4d16 armv7ahf-neon armv7athf-neon armv7ahf-neon-vfpv4 armv7athf-neon-vfpv4"
ARMPKGARCH_tune-armv7ahf             ?= "armv7a"
ARMPKGARCH_tune-armv7athf            ?= "armv7a"
ARMPKGARCH_tune-armv7ahf-vfpv3d16    ?= "armv7a"
ARMPKGARCH_tune-armv7athf-vfpv3d16   ?= "armv7a"
ARMPKGARCH_tune-armv7ahf-vfpv3       ?= "armv7a"
ARMPKGARCH_tune-armv7athf-vfpv3      ?= "armv7a"
ARMPKGARCH_tune-armv7ahf-vfpv4d16    ?= "armv7a"
ARMPKGARCH_tune-armv7athf-vfpv4d16   ?= "armv7a"
ARMPKGARCH_tune-armv7ahf-neon        ?= "armv7a"
ARMPKGARCH_tune-armv7athf-neon       ?= "armv7a"
ARMPKGARCH_tune-armv7ahf-neon-vfpv4  ?= "armv7a"
ARMPKGARCH_tune-armv7athf-neon-vfpv4 ?= "armv7a"
TUNE_FEATURES_tune-armv7ahf             = "${TUNE_FEATURES_tune-armv7a} callconvention-hard"
TUNE_FEATURES_tune-armv7athf            = "${TUNE_FEATURES_tune-armv7at} callconvention-hard"
TUNE_FEATURES_tune-armv7ahf-vfpv3d16    = "${TUNE_FEATURES_tune-armv7a-vfpv3d16} callconvention-hard"
TUNE_FEATURES_tune-armv7athf-vfpv3d16   = "${TUNE_FEATURES_tune-armv7at-vfpv3d16} callconvention-hard"
TUNE_FEATURES_tune-armv7ahf-vfpv3       = "${TUNE_FEATURES_tune-armv7a-vfpv3} callconvention-hard"
TUNE_FEATURES_tune-armv7athf-vfpv3      = "${TUNE_FEATURES_tune-armv7at-vfpv3} callconvention-hard"
TUNE_FEATURES_tune-armv7ahf-vfpv4d16    = "${TUNE_FEATURES_tune-armv7a-vfpv4d16} callconvention-hard"
TUNE_FEATURES_tune-armv7athf-vfpv4d16   = "${TUNE_FEATURES_tune-armv7at-vfpv4d16} callconvention-hard"
TUNE_FEATURES_tune-armv7ahf-neon        = "${TUNE_FEATURES_tune-armv7a-neon} callconvention-hard"
TUNE_FEATURES_tune-armv7athf-neon       = "${TUNE_FEATURES_tune-armv7at-neon} callconvention-hard"
TUNE_FEATURES_tune-armv7ahf-neon-vfpv4  = "${TUNE_FEATURES_tune-armv7a-neon-vfpv4} callconvention-hard"
TUNE_FEATURES_tune-armv7athf-neon-vfpv4 = "${TUNE_FEATURES_tune-armv7at-neon-vfpv4} callconvention-hard"
PACKAGE_EXTRA_ARCHS_tune-armv7ahf             = "${PACKAGE_EXTRA_ARCHS_tune-armv6hf} armv7ahf-vfp"
PACKAGE_EXTRA_ARCHS_tune-armv7athf            = "${PACKAGE_EXTRA_ARCHS_tune-armv6thf} armv7ahf-vfp armv7at2hf-vfp"
PACKAGE_EXTRA_ARCHS_tune-armv7ahf-vfpv3d16    = "${PACKAGE_EXTRA_ARCHS_tune-armv7ahf} armv7ahf-vfpv3d16"
PACKAGE_EXTRA_ARCHS_tune-armv7athf-vfpv3d16   = "${PACKAGE_EXTRA_ARCHS_tune-armv7athf} armv7ahf-vfpv3d16 armv7at2hf-vfpv3d16"
PACKAGE_EXTRA_ARCHS_tune-armv7ahf-vfpv3       = "${PACKAGE_EXTRA_ARCHS_tune-armv7ahf-vfpv3d16} armv7ahf-vfpv3"
PACKAGE_EXTRA_ARCHS_tune-armv7athf-vfpv3      = "${PACKAGE_EXTRA_ARCHS_tune-armv7athf-vfpv3d16} armv7ahf-vfpv3 armv7at2hf-vfpv3"
PACKAGE_EXTRA_ARCHS_tune-armv7ahf-vfpv4d16    = "${PACKAGE_EXTRA_ARCHS_tune-armv7ahf} armv7ahf-vfpv4d16"
PACKAGE_EXTRA_ARCHS_tune-armv7athf-vfpv4d16   = "${PACKAGE_EXTRA_ARCHS_tune-armv7athf} armv7ahf-vfpv4d16 armv7at2hf-vfpv4d16"
PACKAGE_EXTRA_ARCHS_tune-armv7ahf-neon        = "${PACKAGE_EXTRA_ARCHS_tune-armv7ahf} armv7ahf-neon"
PACKAGE_EXTRA_ARCHS_tune-armv7athf-neon       = "${PACKAGE_EXTRA_ARCHS_tune-armv7athf} armv7ahf-neon armv7at2hf-neon"
PACKAGE_EXTRA_ARCHS_tune-armv7ahf-neon-vfpv4  = "${PACKAGE_EXTRA_ARCHS_tune-armv7ahf-neon} armv7ahf-neon-vfpv4"
PACKAGE_EXTRA_ARCHS_tune-armv7athf-neon-vfpv4 = "${PACKAGE_EXTRA_ARCHS_tune-armv7athf-neon} armv7ahf-neon-vfpv4 armv7at2hf-neon-vfpv4"

# Big Endian
AVAILTUNES += "armv7ab armv7atb armv7ab-vfpv3d16 armv7atb-vfpv3d16 armv7ab-vfpv3 armv7atb-vfpv3 armv7ab-vfpv4d16 armv7atb-vfpv4d16 armv7ab-neon armv7atb-neon armv7ab-neon-vfpv4 armv7atb-neon-vfpv4"
ARMPKGARCH_tune-armv7ab             ?= "armv7a"
ARMPKGARCH_tune-armv7atb            ?= "armv7a"
ARMPKGARCH_tune-armv7ab-vfpv3d16    ?= "armv7a"
ARMPKGARCH_tune-armv7atb-vfpv3d16   ?= "armv7a"
ARMPKGARCH_tune-armv7ab-vfpv3       ?= "armv7a"
ARMPKGARCH_tune-armv7atb-vfpv3      ?= "armv7a"
ARMPKGARCH_tune-armv7ab-vfpv4d16    ?= "armv7a"
ARMPKGARCH_tune-armv7atb-vfpv4d16   ?= "armv7a"
ARMPKGARCH_tune-armv7ab-neon        ?= "armv7a"
ARMPKGARCH_tune-armv7atb-neon       ?= "armv7a"
ARMPKGARCH_tune-armv7ab-neon-vfpv4  ?= "armv7a"
ARMPKGARCH_tune-armv7atb-neon-vfpv4 ?= "armv7a"
TUNE_FEATURES_tune-armv7ab             = "${TUNE_FEATURES_tune-armv7a} bigendian"
TUNE_FEATURES_tune-armv7atb            = "${TUNE_FEATURES_tune-armv7at} bigendian"
TUNE_FEATURES_tune-armv7ab-vfpv3d16    = "${TUNE_FEATURES_tune-armv7a-vfpv3d16} bigendian"
TUNE_FEATURES_tune-armv7atb-vfpv3d16   = "${TUNE_FEATURES_tune-armv7at-vfpv3d16} bigendian"
TUNE_FEATURES_tune-armv7ab-vfpv3       = "${TUNE_FEATURES_tune-armv7a-vfpv3} bigendian"
TUNE_FEATURES_tune-armv7atb-vfpv3      = "${TUNE_FEATURES_tune-armv7at-vfpv3} bigendian"
TUNE_FEATURES_tune-armv7ab-vfpv4d16    = "${TUNE_FEATURES_tune-armv7a-vfpv4d16} bigendian"
TUNE_FEATURES_tune-armv7atb-vfpv4d16   = "${TUNE_FEATURES_tune-armv7at-vfpv4d16} bigendian"
TUNE_FEATURES_tune-armv7ab-neon        = "${TUNE_FEATURES_tune-armv7a-neon} bigendian"
TUNE_FEATURES_tune-armv7atb-neon       = "${TUNE_FEATURES_tune-armv7at-neon} bigendian"
TUNE_FEATURES_tune-armv7ab-neon-vfpv4  = "${TUNE_FEATURES_tune-armv7a-neon-vfpv4} bigendian"
TUNE_FEATURES_tune-armv7atb-neon-vfpv4 = "${TUNE_FEATURES_tune-armv7at-neon-vfpv4} bigendian"
PACKAGE_EXTRA_ARCHS_tune-armv7ab             = "${PACKAGE_EXTRA_ARCHS_tune-armv6b} armv7ab-vfp"
PACKAGE_EXTRA_ARCHS_tune-armv7atb            = "${PACKAGE_EXTRA_ARCHS_tune-armv6tb} armv7ab-vfp armv7at2b-vfp"
PACKAGE_EXTRA_ARCHS_tune-armv7ab-vfpv3d16    = "${PACKAGE_EXTRA_ARCHS_tune-armv7ab} armv7ab-vfpv3d16"
PACKAGE_EXTRA_ARCHS_tune-armv7atb-vfpv3d16   = "${PACKAGE_EXTRA_ARCHS_tune-armv7atb} armv7ab-vfpv3d16 armv7at2b-vfpv3d16"
PACKAGE_EXTRA_ARCHS_tune-armv7ab-vfpv3       = "${PACKAGE_EXTRA_ARCHS_tune-armv7ab-vfpv3d16} armv7ab-vfpv3"
PACKAGE_EXTRA_ARCHS_tune-armv7atb-vfpv3      = "${PACKAGE_EXTRA_ARCHS_tune-armv7atb-vfpv3d16} armv7ab-vfpv3 armv7at2b-vfpv3"
PACKAGE_EXTRA_ARCHS_tune-armv7ab-vfpv4d16    = "${PACKAGE_EXTRA_ARCHS_tune-armv7ab} armv7ab-vfpv4d16"
PACKAGE_EXTRA_ARCHS_tune-armv7atb-vfp43d16   = "${PACKAGE_EXTRA_ARCHS_tune-armv7atb} armv7ab-vfpv4d16 armv7at2b-vfpv4d16"
PACKAGE_EXTRA_ARCHS_tune-armv7ab-neon        = "${PACKAGE_EXTRA_ARCHS_tune-armv7ab} armv7ab-neon"
PACKAGE_EXTRA_ARCHS_tune-armv7atb-neon       = "${PACKAGE_EXTRA_ARCHS_tune-armv7atb} armv7ab-neon armv7at2b-neon"
PACKAGE_EXTRA_ARCHS_tune-armv7ab-neon-vfpv4  = "${PACKAGE_EXTRA_ARCHS_tune-armv7ab-neon} armv7ab-neon-vfpv4"
PACKAGE_EXTRA_ARCHS_tune-armv7atb-neon-vfpv4 = "${PACKAGE_EXTRA_ARCHS_tune-armv7atb-neon} armv7ab-neon-vfpv4 armv7at2b-neon-vfpv4"

# Big Endian + HF
AVAILTUNES += "armv7ahfb armv7athfb armv7ahfb-vfpv3d16 armv7athfb-vfpv3d16 armv7ahfb-vfpv3 armv7athfb-vfpv3 armv7ahfb-vfpv4d16 armv7athfb-vfpv4d16 armv7ahfb-neon armv7athfb-neon armv7ahfb-neon-vfpv4 armv7athfb-neon-vfpv4"
ARMPKGARCH_tune-armv7ahfb             ?= "armv7a"
ARMPKGARCH_tune-armv7athfb            ?= "armv7a"
ARMPKGARCH_tune-armv7ahfb-vfpv3d16    ?= "armv7a"
ARMPKGARCH_tune-armv7athfb-vfpv3d16   ?= "armv7a"
ARMPKGARCH_tune-armv7ahfb-vfpv3       ?= "armv7a"
ARMPKGARCH_tune-armv7athfb-vfpv3      ?= "armv7a"
ARMPKGARCH_tune-armv7ahfb-vfpv4d16    ?= "armv7a"
ARMPKGARCH_tune-armv7athfb-vfpv4d16   ?= "armv7a"
ARMPKGARCH_tune-armv7ahfb-neon        ?= "armv7a"
ARMPKGARCH_tune-armv7athfb-neon       ?= "armv7a"
ARMPKGARCH_tune-armv7ahfb-neon-vfpv4  ?= "armv7a"
ARMPKGARCH_tune-armv7athfb-neon-vfpv4 ?= "armv7a"
TUNE_FEATURES_tune-armv7ahfb             = "${TUNE_FEATURES_tune-armv7ahf} bigendian"
TUNE_FEATURES_tune-armv7athfb            = "${TUNE_FEATURES_tune-armv7athf} bigendian"
TUNE_FEATURES_tune-armv7ahfb-vfpv3d16    = "${TUNE_FEATURES_tune-armv7ahf-vfpv3d16} bigendian"
TUNE_FEATURES_tune-armv7athfb-vfpv3d16   = "${TUNE_FEATURES_tune-armv7athf-vfpv3d16} bigendian"
TUNE_FEATURES_tune-armv7ahfb-vfpv3       = "${TUNE_FEATURES_tune-armv7ahf-vfpv3} bigendian"
TUNE_FEATURES_tune-armv7athfb-vfpv3      = "${TUNE_FEATURES_tune-armv7athf-vfpv3} bigendian"
TUNE_FEATURES_tune-armv7ahfb-vfpv4d16    = "${TUNE_FEATURES_tune-armv7ahf-vfpv4d16} bigendian"
TUNE_FEATURES_tune-armv7athfb-vfpv4d16   = "${TUNE_FEATURES_tune-armv7athf-vfpv4d16} bigendian"
TUNE_FEATURES_tune-armv7ahfb-neon        = "${TUNE_FEATURES_tune-armv7ahf-neon} bigendian"
TUNE_FEATURES_tune-armv7athfb-neon       = "${TUNE_FEATURES_tune-armv7athf-neon} bigendian"
TUNE_FEATURES_tune-armv7ahfb-neon-vfpv4  = "${TUNE_FEATURES_tune-armv7ahf-neon-vfpv4} bigendian"
TUNE_FEATURES_tune-armv7athfb-neon-vfpv4 = "${TUNE_FEATURES_tune-armv7athf-neon-vfpv4} bigendian"
PACKAGE_EXTRA_ARCHS_tune-armv7ahfb             = "${PACKAGE_EXTRA_ARCHS_tune-armv6hfb} armv7ahfb-vfp"
PACKAGE_EXTRA_ARCHS_tune-armv7athfb            = "${PACKAGE_EXTRA_ARCHS_tune-armv6thfb} armv7ahfb-vfp armv7at2hfb-vfp"
PACKAGE_EXTRA_ARCHS_tune-armv7ahfb-vfpv3d16    = "${PACKAGE_EXTRA_ARCHS_tune-armv7ahfb} armv7ahfb-vfpv3d16"
PACKAGE_EXTRA_ARCHS_tune-armv7athfb-vfpv3d16   = "${PACKAGE_EXTRA_ARCHS_tune-armv7athfb} armv7ahfb-vfpv3d16 armv7at2hfb-vfpv3d16"
PACKAGE_EXTRA_ARCHS_tune-armv7ahfb-vfpv3       = "${PACKAGE_EXTRA_ARCHS_tune-armv7ahfb-vfpv3d16} armv7ahfb-vfpv3"
PACKAGE_EXTRA_ARCHS_tune-armv7athfb-vfpv3      = "${PACKAGE_EXTRA_ARCHS_tune-armv7athfb-vfpv3d16} armv7ahfb-vfpv3 armv7at2hfb-vfpv3"
PACKAGE_EXTRA_ARCHS_tune-armv7ahfb-vfpv4d16    = "${PACKAGE_EXTRA_ARCHS_tune-armv7ahfb} armv7ahfb-vfpv4d16"
PACKAGE_EXTRA_ARCHS_tune-armv7athfb-vfpv4d16   = "${PACKAGE_EXTRA_ARCHS_tune-armv7athfb} armv7ahfb-vfpv4d16 armv7at2hfb-vfpv4d16"
PACKAGE_EXTRA_ARCHS_tune-armv7ahfb-neon        = "${PACKAGE_EXTRA_ARCHS_tune-armv7ahfb} armv7ahfb-neon"
PACKAGE_EXTRA_ARCHS_tune-armv7athfb-neon       = "${PACKAGE_EXTRA_ARCHS_tune-armv7athfb} armv7ahfb-neon armv7at2hfb-neon"
PACKAGE_EXTRA_ARCHS_tune-armv7ahfb-neon-vfpv4  = "${PACKAGE_EXTRA_ARCHS_tune-armv7ahfb-neon} armv7ahfb-neon-vfpv4"
PACKAGE_EXTRA_ARCHS_tune-armv7athfb-neon-vfpv4 = "${PACKAGE_EXTRA_ARCHS_tune-armv7athfb-neon} armv7ahfb-neon-vfpv4 armv7at2hfb-neon-vfpv4"