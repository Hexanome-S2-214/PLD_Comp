import shutil
import pytest
from subprocess import run
import glob
from typing import Tuple

PROGRAMS_DIR = 'tests/testfiles'
ALLOW_FAIL = [
    'operations_arithmetiques_base-div_plus',
    'operations_arithmetiques_base-mult_plus',
    'commentaires-comment',
    'declaration_affectation-affect_enchainee_parentheses',
    'structures_if_while-return_multiples_2',
]

def get_files_path(dir):
    return [f for f in glob.glob(dir + '/**/*.c', recursive=True)]

def get_pretty_name(file_param: Tuple[int, str]) -> str:
    index, file_path = file_param
    return f"{index + 1}-{file_path.replace(PROGRAMS_DIR, '')[1:-2].replace('/', '-')}"

@pytest.fixture(params=enumerate(get_files_path(PROGRAMS_DIR)), ids=get_pretty_name)
def file_param(request):
    return request.param

@pytest.fixture(scope='session', autouse=True)
def setup():
    shutil.rmtree('ifcc-test-output', ignore_errors=True)
    pass

def test_programs(file_param):
    index, file_path = file_param
    pretty_name = get_pretty_name(file_param)
    allow_fail = any(test_name in pretty_name for test_name in ALLOW_FAIL)

    result = run(['python', 'tests/ifcc-test.py', file_path, '--output-subdirectory', get_pretty_name(file_param)], capture_output=True, text=True)
    
    if result.returncode == 0:
        assert True
    elif allow_fail:
        pytest.xfail(f"Test failed for {file_path} (as expected)")
    else:
        pytest.fail(f"""
            Test failed for {file_path} with exit code {result.returncode}:
            STDOUT: {result.stdout}
            STDERR: {result.stderr}
        """)