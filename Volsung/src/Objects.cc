
#include <fstream>
#include <vector>
#include <cmath>

#include "Objects.hh"

namespace Volsung {

void AddObject::run(buf &in, buf &out)
{
	out[0][0] = in[0][0] + default_value;
}

AddObject::AddObject(std::vector<TypedValue> args)
{
	init(2, 1, args, { &default_value });
	set_defval(&default_value, default_value, 1);
}



void DelayObject::run(buf &in, buf &out)
{
	float lower = in[0][-sample_delay];
	float upper = in[0][-(sample_delay+0.5)];
	float ratio = sample_delay - (int) sample_delay;
	
	out[0][0] = (1-ratio) * lower + ratio * upper;
}

DelayObject::DelayObject(std::vector<TypedValue> args)
{
	init(2, 1, args, { &sample_delay });
	set_defval(&sample_delay, sample_delay, 1);
	request_buffer_size(sample_delay + 1);
}



void DriveObject::run(buf& in, buf& out)
{
	out[0][0] = tanh(in[0][0]);
}

DriveObject::DriveObject(std::vector<TypedValue> args)
{
	set_io(2, 1);
}



void FileoutObject::run(buf &in, buf &out)
{
	if (is_connected(0)) in_data.push_back(in[0][0]);
	if (out_data.size()) {
		out[0][0] = out_data[pos++];
		if (pos >= out_data.size()) pos = out_data.size()-1;
	}
}

void FileoutObject::finish()
{
	std::ofstream file(filename, std::fstream::out | std::fstream::binary);
	
	for (uint n = 0; n < in_data.size(); n++)
		file.write((const char*)& in_data[n], sizeof(float));

	file.close();
}

FileoutObject::FileoutObject(std::vector<TypedValue> args)
{
	filename = args[0].get_value<std::string>();
	std::ifstream file(filename, std::ios::in | std::ios::binary | std::ios::ate);
	
	if (file.good()) {
		out_data.resize(file.tellg() / sizeof(float));
		file.seekg(0);
		file.read(reinterpret_cast<char*>(out_data.data()), out_data.size() * sizeof(float));
	}
	set_io(1, 1);
}



void FilterObject::run(buf& x, buf& y)
{
	b = 2 - cos(TAU * frequency / sample_rate);
	b = sqrt(b*b - 1) - b;
	a = 1 + b;

	y[0][0] = a*x[0][0] - b*y[0][-1];
}

FilterObject::FilterObject(std::vector<TypedValue> args)
{
	init(2, 1, args, { &frequency });
	set_defval(&frequency, frequency, 1);
}



void MultObject::run(buf &in, buf &out)
{
	out[0][0] = in[0][0] * default_value;
}

MultObject::MultObject(std::vector<TypedValue> args)
{
	init(2, 1, args, { &default_value });
	set_defval(&default_value, default_value, 1);
}



void NoiseObject::run(buf &, buf &out)
{
	out[0][0] = distribution(generator);
}

NoiseObject::NoiseObject(std::vector<TypedValue>) :
	distribution(-1.0f, 1.0f)
{ set_io(0, 1); }



void OscillatorObject::run(buf &, buf &out)
{
	out[0][0] = sinf(TAU * phase);

	phase = phase + frequency / sample_rate;

	if (phase >= 1.0) { phase -= 1.0; }
	if (gate_opened(1)) phase = 0;
}

OscillatorObject::OscillatorObject(std::vector<TypedValue> args) :  phase(0)
{
	init(2, 1, args, {&frequency} );
	set_defval(&frequency, frequency, 0);
}



void SquareObject::run(buf &, buf &out)
{	
	out[0][0] = (float)sign<float>(sinf(TAU * phase) + pw);

	phase = phase + frequency / sample_rate;

	if (phase >= 1.0) { phase -= 1.0; }
}

SquareObject::SquareObject(std::vector<TypedValue> args)
{
	init(2, 1, args, { &frequency, &pw });
	set_defval(&frequency, frequency, 0);
	set_defval(&pw, pw, 1);
}



void UserObject::run(buf& in, buf& out)
{
	if (callback)
		callback(in, out, user_data);
}

UserObject::UserObject(std::vector<TypedValue> args)
{
	float inputs = 0, outputs = 0;
	inputs  = args[0].get_value<float>();
	outputs = args[1].get_value<float>();
	set_io(inputs, outputs);
}



void AudioInputObject::run(buf& in, buf& out)
{
	for (auto& output : out) {
		output[0] = data[0];
	}
}

AudioInputObject::AudioInputObject(std::vector<TypedValue> args)
{
	float outputs = 0;
	outputs = args[0].get_value<float>();
	set_io(0, outputs);
	data.resize(outputs);
}



void AudioOutputObject::run(buf& in, buf& out)
{
	for (int n = 0; n < in.size(); n++) data[n] = in[n][0];
}

AudioOutputObject::AudioOutputObject(std::vector<TypedValue> args)
{
	float inputs = 0;
	inputs = args[0].get_value<float>();
	set_io(inputs, 0);
	data.resize(inputs);
}



void ComparatorObject::run(buf &in, buf &out)
{
	if (in[0][0] > value) out[0][0] = 1.f;
	else out[0][0] = 0.f;
}

ComparatorObject::ComparatorObject(std::vector<TypedValue> args)
{
	init(2, 1, args, { &value });
	set_defval(&value, value, 1);
}


void TimerObject::run(buf&, buf &out)
{
	out[0][0] = value;
	value += 1.f / sample_rate;
	if (gate_opened(0)) value = 0.f;
}

TimerObject::TimerObject(std::vector<TypedValue>)
{
	set_io(1, 1);
}


void ClockObject::run(buf&, buf &out)
{
	out[0][0] = 0;
	if (elapsed >= interval) {
		out[0][0] = 1;
		elapsed = 0.f;
	}
	
	elapsed += 1.f;
}

ClockObject::ClockObject(std::vector<TypedValue> args)
{
	init(1, 1, args, { &interval });
	set_defval(&interval, interval, 0);
}


void DivisionObject::run(buf &in, buf &out)
{
	out[0][0] = in[0][0] / divisor;
}

DivisionObject::DivisionObject(std::vector<TypedValue> args)
{
	init(2, 1, args, { &divisor });
	set_defval(&divisor, divisor, 1);
}


void SubtractionObject::run(buf &in, buf &out)
{
	out[0][0] = in[0][0] - subtrahend;
}

SubtractionObject::SubtractionObject(std::vector<TypedValue> args)
{
	init(2, 1, args, { &subtrahend });
	set_defval(&subtrahend, subtrahend, 1);
}


void ModuloObject::run(buf &in, buf &out)
{
	out[0][0] = std::fmod(in[0][0], divisor);
}

ModuloObject::ModuloObject(std::vector<TypedValue> args)
{
	init(2, 1, args, { &divisor });
	set_defval(&divisor, divisor, 1);
}


void AbsoluteValueObject::run(buf &in, buf &out)
{
	out[0][0] = std::fabs(in[0][0]);
}

AbsoluteValueObject::AbsoluteValueObject(std::vector<TypedValue>)
{
	set_io(1, 1);
}


void StepSequence::run(buf& in, buf& out)
{
	if (gate_opened(0)) current = ++current % sequence.size();
	out[0][0] = sequence.data[current];
}

StepSequence::StepSequence(std::vector<TypedValue> arguments)
{
	set_io(1, 1);
	sequence = arguments[0].get_value<Sequence>();
}

void PowerObject::run(buf& in, buf& out)
{
	out[0][0] = std::pow(in[0][0], exponent);
}

PowerObject::PowerObject(std::vector<TypedValue> arguments)
{
	init(2, 1, arguments, { &exponent });
	set_defval(&exponent, exponent, 1);
}




void EnvelopeObject::run(buf&, buf& out)
{
	if (gate_opened(0)) time = 0;
	if (time > length) time = length;
	
	float ratio = float(time) / (length+0.001);
	out[0][0] = (1-ratio) * start + ratio * end;
	time++;
}

EnvelopeObject::EnvelopeObject(std::vector<TypedValue> arguments)
{
	init(4, 1, arguments, { &length, &start, &end });
	set_defval(&length, length, 1);
	set_defval(&start, start, 2);
	set_defval(&end, end, 3);
}

void RoundObject::run(buf& in, buf& out)
{
	out[0][0] = std::round(in[0][0]);
}

RoundObject::RoundObject(std::vector<TypedValue>)
{
	set_io(1, 1);
}

void SequenceObject::run(buf& in, buf& out)
{
	out[0][0] = sequence.data[(int) in[0][0]];
}

SequenceObject::SequenceObject(std::vector<TypedValue> arguments)
{
	set_io(1, 1);
	sequence = arguments[0].get_value<Sequence>();
}

void SampleAndHoldObject::run(buf& in, buf& out)
{
	if (gate_opened(1)) value = in[0][0];
	out[0][0] = value;
}

SampleAndHoldObject::SampleAndHoldObject(std::vector<TypedValue> arguments)
{
	set_io(2, 1);
}

void ConstObject::run(buf&, buf& out)
{
	out[0][0] = value;
}

ConstObject::ConstObject(std::vector<TypedValue> arguments)
{
	value = arguments[0].get_value<float>();
	set_io(0, 1);
}

void SawObject::run(buf&, buf& out)
{
	if (gate_opened(1)) phase = -1;
	
	phase += std::abs(2.f * frequency / sample_rate);
	if (phase > 1.f) phase = -1.f;
	
	if (frequency < 0) out[0][0] = -phase;
	else out[0][0] = phase;
}

SawObject::SawObject(std::vector<TypedValue> arguments)
{
	init(2, 1, arguments, { &frequency });
	set_defval(&frequency, frequency, 0);
}

void TriangleObject::run(buf&, buf& out)
{
	if (gate_opened(1)) phase = 0;
	
	phase += frequency / sample_rate;
	if (phase >= 1.f) phase -= 1.f;
	out[0][0] = 2.f * fabs(2.f * phase - 1.f) - 1.f;
}

TriangleObject::TriangleObject(std::vector<TypedValue> arguments)
{
	init(2, 1, arguments, { &frequency });
	set_defval(&frequency, frequency, 0);
}

}
