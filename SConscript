###################################################################################################
# @author R. Matt McCann
# @brief Build script for the FreeRTOS library and its port components
# @subsection Copyright Notice
# &copy; 2014 Battelle Memorial Institute
#
# One may inject configuration into the build from a higher-order project by exporting a build
# environment called 'free_rtos_env'.
#
# One must add an inclusion path that includes the FreeRTOSConfig.h header and the desired port 
# in the exported build environment. 
#
# When linking, use the following linkage flags:
#
# -lfree_rtos -l[port_of_your_choicing]
###################################################################################################

import build_helper

# Name of the produced library
target_name = "free_rtos"

# Inclusion paths for the build
includes = [
    'include'
]

# Source files to be built
sources = Split("""
croutine.c
list.c
queue.c
tasks.c
timers.c
""")

###################################################################################################
# Nothing below this should need to be edited!
###################################################################################################
env = Environment()

# Try to import the build environment
try:
    Import('free_rtos_env')
    env = free_rtos_env.Clone()

except:
    raise Exception(
            "Error: Expected you to export a SCons build environment called 'free_rtos_env'!"
        )

# Configure the build directory
build_dir = '#.build/%s/' % target_name
VariantDir(build_dir, '.')

# Add the build settings
env.Append(CPPPATH = includes)

# Add the port specific code
build_flags = env._dict['CPPFLAGS']
if '-DFREE_RTOS_PORT=GCC_ARM_CM4F' in build_flags:
    sources.extend([
        'portable/GCC/ARM_CM4F/port.c',
        'portable/MemMang/heap_4.c'
    ])
    env.Append(CPPPATH = ['%s/portable/GCC/ARM_CM4F' % Dir('.').abspath])

elif '-DFREE_RTOS_PORT=GCC_POSIX' in build_flags:
    sources.extend([
        'portable/GCC/Posix/port.c',
        'portable/MemMang/heap_4.c'
    ])
    env.Append(CPPPATH = ['%s/portable/GCC/Posix' % Dir('.').abspath])

else:
    raise Exception("Error: Please add a valid -DFREE_RTOS_PORT= flag to build settings!")

# Add the build prefix to the source files
my_source = build_helper.decorateSource(sources, build_dir)

# Build the library
try:
    target = env.Library(target = "#lib/%s" % target_name, source = sources)
    env.Alias(target_name, target)

except:
    raise Exception("Error: This library failed to build! Possible causes:\n" + 
            "1. Did you remember to add an inclusion path that contains your FreeRTOSConfig.h?\n" + 
            "2. Did you define which port you want included using the -DFREE_RTOS_PORT= flag?"
        )
