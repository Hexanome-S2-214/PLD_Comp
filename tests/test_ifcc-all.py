import pytest
from subprocess import run
import glob
from typing import Tuple

PROGRAMS_DIR = 'tests/testfiles'

def get_files_path(dir):
    return [f for f in glob.glob(dir + '/**/*.c', recursive=True)]

def get_pretty_name(file_param: Tuple[int, str]) -> str:
    index, file_path = file_param
    return f"{index + 1}-{file_path.replace(PROGRAMS_DIR, '')[1:-2].replace('/', '-')}"

@pytest.fixture(params=enumerate(get_files_path(PROGRAMS_DIR)), ids=get_pretty_name)
def file_param(request):
    return request.param

def test_programs(file_param):
    index, file_path = file_param

    result = run(['python', 'tests/ifcc-test.py', file_path, '--output-subdirectory', get_pretty_name(file_param)], capture_output=True, text=True)
    
    assert result.returncode == 0, f"""
        Test failed for {file_path} with exit code {result.returncode}:
        STDOUT: {result.stdout}
        STDERR: {result.stderr}
    """