import pytest
from subprocess import run
import glob

PROGRAMS_DIR = 'tests/testfiles'

def get_files_path(dir):
    return [f for f in glob.glob(dir + '/**/*.c', recursive=True)]

@pytest.fixture(params=get_files_path(PROGRAMS_DIR), ids=lambda f: f)
def file_path(request):
    return request.param

def test_programs(file_path):
    result = run(['python', 'tests/ifcc-test.py', file_path], capture_output=True, text=True)
    
    assert result.returncode == 0, f"""
        Test failed for {file_path} with exit code {result.returncode}:
        STDOUT: {result.stdout}
        STDERR: {result.stderr}
    """