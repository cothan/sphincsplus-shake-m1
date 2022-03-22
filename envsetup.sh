echo "Setting up Python environment"

PATH_ROOT=$(builtin cd $(dirname $0) && pwd)

# Path to root of specification
export PYTHONPATH=$PATH_ROOT/asm/gen:$PYTHONPATH
